#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int id;
    int at;
    int bt;
    int remain;
    int prio;
    int done;
    int visit;
    int wt;
    int tat;
    int rt;
    int ct;
};

typedef struct Node node;

void fcfs(node pro[],int n) //first come first serve
{
    printf("FCFS\n");
    int ready[100],r=0,front=0,back=-1,cpu=0;
    int donecount=0;
    
    node temp;
    for(int i=0;i<n;i++)
    {
        pro[i].done=0;
        pro[i].remain=pro[i].bt;
    }
    //sort by arrival time
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(pro[i].at<pro[j].at) //swap
            {
                temp=pro[i];
                pro[i]=pro[j];
                pro[j]=temp;
            }
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     printf("%i \t",pro[i].at);
    // }
    for(int time=0;donecount<n;time++)
    {
        //printf("%i  ",time);
        for(int i=0;i<n;i++)
        {
            if(pro[i].at==time)
            {
                //printf("Working\n");
                back++;
                ready[back]=i;
            }
            //if(pro[i].at>time) break;
        }
        // printf("\nReady queue at time %i is : ",time);
        // for(int i=front;i<=back;i++)
        // {
        //     printf("%i ",ready[i]);
        // }
        if(front>back) continue;
        if(pro[ready[front]].remain>0 && pro[ready[front]].done==0)
        {
            pro[ready[front]].remain--;
        }
        if(pro[ready[front]].remain==0 && pro[ready[front]].done==0)
        {
            pro[ready[front]].done=1;
            //tat
            pro[ready[front]].ct=time+1;
            pro[ready[front]].tat=pro[ready[front]].ct-pro[ready[front]].at;
            pro[ready[front]].wt=pro[ready[front]].tat-pro[ready[front]].bt;
            printf("P%i ",pro[ready[front]].id);
            //printf("\nfront : %i\n",front);
            front++;
            donecount++;
            
        }
    }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("P%i\t%i\t%i\t%i\t%i\t%i\n",pro[i].id,pro[i].at,pro[i].bt,pro[i].ct,pro[i].tat,pro[i].wt);
    }
}

void sjf(node pro[],int n) //shortest job first
{
    printf("SJF\n");
    int ready[100],r=0,front=0,back=-1,cpu=0;
    int donecount=0;
    
    node temp;
    for(int i=0;i<n;i++)
    {
        pro[i].done=0;
    }
    //sort by arrival time
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(pro[i].at<pro[j].at) //swap
            {
                temp=pro[i];
                pro[i]=pro[j];
                pro[j]=temp;
            }
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     printf("%i \t",pro[i].at);
    // }
    for(int time=0;donecount<n;time++)
    {
        //printf("%i  ",time);
        for(int i=0;i<n;i++)
        {
            if(pro[i].at==time)
            {
                //printf("Working\n");
                back++;
                ready[back]=i;
            }
            //if(pro[i].at>time) break;
        }
        //while starting the scheduling first sort ready queue
        if(time==0)
        {
            for(int i=front;i<=back;i++)
            {
                for(int j=front;j<=back;j++)
                {
                    if(pro[ready[i]].bt>pro[ready[j]].bt)
                    {
                        int temp2=ready[i];
                        ready[i]=ready[j];
                        ready[j]=temp2;
                    }
                }
            }
        }
        // printf("\nReady queue at time %i is : ",time);
        // for(int i=front;i<=back;i++)
        // {
        //     printf("%i ",ready[i]);
        // }
        if(front>back) continue;
        if(pro[ready[front]].bt>0 && pro[ready[front]].done==0)
        {
            pro[ready[front]].bt--;
        }
        if(pro[ready[front]].bt==0 && pro[ready[front]].done==0)
        {
            pro[ready[front]].done=1;
            printf("P%i ",pro[ready[front]].id);
            //printf("\nfront : %i\n",front);
            front++;
            //sort ready queue
            for(int i=front;i<=back;i++)
            {
                for(int j=i+1;j<=back;j++)
                {
                    if(pro[ready[i]].bt>pro[ready[j]].bt)
                    {
                        int temp2=ready[i];
                        ready[i]=ready[j];
                        ready[j]=temp2;
                    }
                }
            }
            //sort ready queue
            donecount++;
            
        }
    }
}

void srtf(node pro[],int n) //shortest job first
{
    printf("SRTF\n");
    int ready[100],r=0,front=0,back=-1,cpu=0;
    int donecount=0;
    
    node temp;
    for(int i=0;i<n;i++)
    {
        pro[i].done=0;
    }
    //sort by arrival time
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(pro[i].at<pro[j].at) //swap
            {
                temp=pro[i];
                pro[i]=pro[j];
                pro[j]=temp;
            }
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     printf("%i \t",pro[i].at);
    // }
    for(int time=0;donecount<n;time++)
    {
        //printf("%i  ",time);
        for(int i=0;i<n;i++)
        {
            if(pro[i].at==time)
            {
                //printf("Working\n");
                back++;
                ready[back]=i;
            }
            //if(pro[i].at>time) break;
        }
        //always sort the ready queue on the basis of burst time
        for(int i=front;i<=back;i++)
        {
            for(int j=front+1;j<=back;j++)
            {
                if(pro[ready[i]].bt>pro[ready[j]].bt)
                {
                    int temp2=ready[i];
                    ready[i]=ready[j];
                    ready[j]=temp2;
                }
            }
        }
        // printf("\nReady queue at time %i is : ",time);
        // for(int i=front;i<=back;i++)
        // {
        //     printf("P%i ",pro[ready[i]].id);
        //     //printf("%i\t",ready[i]);
        // }
        if(front>back) continue; //idle
        if(pro[ready[front]].bt>0 && pro[ready[front]].done==0)
        {
            pro[ready[front]].bt--;
            //printf("\nP%d",pro[ready[front]].id);
        }
        if(pro[ready[front]].bt==0 && pro[ready[front]].done==0)
        {
            pro[ready[front]].done=1;
            printf("\n Finished P%i ",pro[ready[front]].id);
            //printf("\nfront : %i\n",front);
            front++;
            donecount++;
        }
    }
}

void rr(node pro[], int n) //round robin
{
    int tq,ping;
    tq=2;
    printf("Round Robin\n");
    int ready[100],front=0,back=-1,cpu=0;
    int donecount=0;
    
    node temp;
    for(int i=0;i<n;i++)
    {
        pro[i].done=0;
        pro[i].visit=0;
    }
    //sort by arrival time
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(pro[i].at<pro[j].at) //swap
            {
                temp=pro[i];
                pro[i]=pro[j];
                pro[j]=temp;
            }
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     printf("%i \t",pro[i].at);
    // }
    for(int time=0;donecount<n;time++)
    {
        //printf("%i  ",time);
        for(int i=0;i<n;i++) 
        {
            if(pro[i].at<=time && pro[i].done==0 && pro[i].visit==0)
            {
                //printf("Working\n");
                back++;
                ready[back]=i;
                pro[i].visit=1;
            }
            //if(pro[i].at>time) break;
        }
        // printf("\nReady queue at time %i is : ",time);
        // for(int i=front;i<=back;i++)
        // {
        //     printf("%i ",ready[i]);
        // }
        if(front>back) continue;//idle
        if(pro[ready[front]].bt<=tq && pro[ready[front]].done==0)
        {
            if(pro[ready[front]].bt>0 && pro[ready[front]].done==0)
            {
                pro[ready[front]].bt--;
            }
            if(pro[ready[front]].bt==0 && pro[ready[front]].done==0)
            {
                pro[ready[front]].done=1;
                printf("P%i ",pro[ready[front]].id);
                //printf("\nfront : %i\n",front);
                front++;
                donecount++; 
            }
        }
        else
        {
            time+=tq;
            for(int k=0;k<n;k++)
            {
                if(pro[k].at<=time && pro[k].done==0 && pro[k].visit==0)
                {
                    //printf("Working\n");
                    back++;
                    ready[back]=k;
                    pro[k].visit=1;
                }
            }
            pro[ready[front]].bt-=tq;
            back++;
            ready[back]=ready[front];
            front++;
        }
    }
}

void nonpreprio(node pro[],int n) //non premtive priority
{
    printf("Non-premtive priority\n");
    int ready[100],r=0,front=0,back=-1,cpu=0;
    int donecount=0;
    
    node temp;
    for(int i=0;i<n;i++)
    {
        pro[i].done=0;
    }
    //sort by arrival time
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(pro[i].at<pro[j].at) //swap
            {
                temp=pro[i];
                pro[i]=pro[j];
                pro[j]=temp;
            }
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     printf("%i \t",pro[i].at);
    // }
    for(int time=0;donecount<n;time++)
    {
        //printf("%i  ",time);
        for(int i=0;i<n;i++)
        {
            if(pro[i].at==time)
            {
                //printf("Working\n");
                back++;
                ready[back]=i;
            }
            //if(pro[i].at>time) break;
        }
        if(time==0)
        {
            for(int i=front;i<=back;i++)
            {
                for(int j=front;j<=back;j++)
                {
                    if(pro[ready[i]].prio<pro[ready[j]].prio)
                    {
                        int temp1=ready[i];
                        ready[i]=ready[j];
                        ready[j]=temp1;
                    }
                }
            }
        }
        // printf("\nReady queue at time %i is : ",time);
        // for(int i=front;i<=back;i++)
        // {
        //     printf("%i ",ready[i]);
        // }
        if(front>back) continue;
        if(pro[ready[front]].bt>0 && pro[ready[front]].done==0)
        {
            pro[ready[front]].bt--;
            printf("\ntime : %i ----->P%d\t",time,pro[ready[front]].id);
        }
        if(pro[ready[front]].bt==0 && pro[ready[front]].done==0)
        {
            pro[ready[front]].done=1;
            printf("P%i ",pro[ready[front]].id);
            //printf("\nfront : %i\n",front);
            front++;
            donecount++;
            for(int i=front;i<=back;i++)
            {
                for(int j=i+1;j<=back;j++)
                {
                    if(pro[ready[i]].prio<pro[ready[j]].prio)
                    {
                        int temp=ready[i];
                        ready[i]=ready[j];
                        ready[j]=temp;
                    }
                }
            }
        }
    }
}

void preprio(node pro[],int n) //premtive priority
{
    printf("Premtive priority\n");
    int ready[100],r=0,front=0,back=-1,cpu=0;
    int donecount=0;
    
    node temp;
    for(int i=0;i<n;i++)
    {
        pro[i].done=0;
    }
    //sort by arrival time
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(pro[i].at<pro[j].at) //swap
            {
                temp=pro[i];
                pro[i]=pro[j];
                pro[j]=temp;
            }
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     printf("%i \t",pro[i].at);
    // }
    for(int time=0;donecount<n;time++)
    {
        //printf("%i  ",time);
        for(int i=0;i<n;i++)
        {
            if(pro[i].at==time)
            {
                //printf("Working\n");
                back++;
                ready[back]=i;
            }
            //if(pro[i].at>time) break;
        }
        for(int i=front;i<=back;i++)
        {
            for(int j=i+1;j<=back;j++)
            {
                if(pro[ready[i]].prio<pro[ready[j]].prio)
                {
                    int temp1=ready[i];
                    ready[i]=ready[j];
                    ready[j]=temp1;
                }
            }
        }
        // printf("\nReady queue at time %i is : ",time);
        // for(int i=front;i<=back;i++)
        // {
        //     printf("%i ",ready[i]);
        // }
        if(front>back) continue;
        if(pro[ready[front]].bt>0 && pro[ready[front]].done==0)
        {
            pro[ready[front]].bt--;
            printf("\ntime : %i ----->P%d\t",time,pro[ready[front]].id);
        }
        if(pro[ready[front]].bt==0 && pro[ready[front]].done==0)
        {
            pro[ready[front]].done=1;
            printf("P%i ",pro[ready[front]].id);
            //printf("\nfront : %i\n",front);
            front++;
            donecount++;
                              // for(int i=front;i<=back;i++)
            // {
            //     for(int j=i+1;j<=back;j++)
            //     {
            //         if(pro[ready[i]].prio<pro[ready[j]].prio)
            //         {
            //             int temp=ready[i];
            //             ready[i]=ready[j];
            //             ready[j]=temp;
            //         }
            //     }
            // }
        }
    }
}

int main()
{
    int n=5;
    node pro[n];
    pro[0].at=0, pro[1].at=5, pro[2].at=1, pro[3].at=6, pro[4].at=8;
    pro[0].bt=8,pro[1].bt=2,pro[2].bt=7,pro[3].bt=3,pro[4].bt=5;
    pro[0].prio=3,pro[1].prio=4,pro[2].prio=9,pro[3].prio=7,pro[4].prio=8;
    for(int i=0;i<n;i++)
    {
        pro[i].id=i+1;
    }

    fcfs(pro,n);
    //sjf(pro,n);
    //srtf(pro,n);
    //rr(pro,n);
    //preprio(pro,n);
}