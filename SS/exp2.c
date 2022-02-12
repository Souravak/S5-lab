#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int id;
    int at;
    int bt;
    int rt;
    int tat;
    int ct;
    int wt;
    int prio;
    int visit;
};
typedef struct Node node;
node pro[20];

void reset(int n)
{
    for(int i=0;i<n;i++)
    {
        pro[i].rt=pro[i].bt;
        pro[i].tat=pro[i].ct=pro[i].wt=0;
    }
}
void fcfs(int n)
{
    reset(n);
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(pro[i].at>pro[j].at)
            {
                //swap
                node temp=pro[i];
                pro[i]=pro[j];
                pro[j]=temp; //swapped
            }
        }
    }
    //printf("Working");
    int front=0, back=-1;
    int ready[100];
    for(int time=0;count<n;time++)
    {
        for(int i=0;i<n;i++)
        {
            if(pro[i].at==time)
            {
                back++;
                ready[back]=i;
            }
        }
        if(pro[ready[front]].rt>0) pro[ready[front]].rt--;
        if(pro[ready[front]].rt==0)
        {
            pro[ready[front]].ct = time+1;
            pro[ready[front]].tat = pro[ready[front]].ct - pro[ready[front]].at;
            pro[ready[front]].wt = pro[ready[front]].tat - pro[ready[front]].bt;
            front++;
            count++;
        }
    }
    printf("FCFS\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    float total=0;
    for(int i=0;i<n;i++)
    {
        printf("%i\t%i\t%i\t%i\t%i\t%i\n",pro[i].id,pro[i].at,pro[i].bt,pro[i].ct,pro[i].tat,pro[i].wt);
        total+=pro[i].wt;
    }
    printf("\nAVG WT = %0.2f\n",total/n);
    printf("\n");
    
}

void sjf(int n)
{
    reset(n);
    int count=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(pro[i].at>pro[j].at)
            {
                //swap
                node temp=pro[i];
                pro[i]=pro[j];
                pro[j]=temp; //swapped
            }
        }
    }
    int front=0, back=-1;
    int ready[100];
    for(int time=0;count<n;time++)
    {
        for(int i=0;i<n;i++)
        {
            if(pro[i].at==time)
            {
                back++;
                ready[back]=i;
            }
        }
        if(pro[ready[front]].rt>0) pro[ready[front]].rt--;
        if(pro[ready[front]].rt==0)
        {
            
            pro[ready[front]].ct=time+1;
            pro[ready[front]].tat = pro[ready[front]].ct - pro[ready[front]].at;
            pro[ready[front]].wt = pro[ready[front]].tat - pro[ready[front]].bt;
            front++;
            count++;
            if(front>back) continue;
            for(int i=front;i<back;i++)
            {
                for(int j=i+1;j<back;j++)
                {
                    if(pro[ready[i]].bt>pro[ready[i]].bt)
                    {
                        int t=ready[i];
                        ready[i]=ready[j];
                        ready[j]=t;
                    }
                }
            }
        }
    }
    printf("SJF\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    float total=0;
    for(int i=0;i<n;i++)
    {
        printf("%i\t%i\t%i\t%i\t%i\t%i\n",pro[i].id,pro[i].at,pro[i].bt,pro[i].ct,pro[i].tat,pro[i].wt);
        total+=pro[i].wt;
    }
    printf("\nAVG WT = %0.2f\n",total/n);
    printf("\n");
}

void prio(int n)
{
    reset(n);
    int count=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(pro[i].at>pro[j].at)
            {
                //swap
                node temp=pro[i];
                pro[i]=pro[j];
                pro[j]=temp; //swapped
            }
        }
    }
    int front=0, back=-1;
    int ready[20];
    for(int time=0;count<n;time++)
    {
        for(int i=0;i<n;i++)
        {
            if(pro[i].at==time)
            {
                back++;
                ready[back]=i;
            }
        }
        if(pro[ready[front]].rt>0) pro[ready[front]].rt--;
        if(pro[ready[front]].rt==0)
        {
            
            pro[ready[front]].ct=time+1;
            pro[ready[front]].tat = pro[ready[front]].ct - pro[ready[front]].at;
            pro[ready[front]].wt = pro[ready[front]].tat - pro[ready[front]].bt;
            front++;
            count++;
            if(front>back) continue;
            for(int i=front;i<back;i++)
            {
                for(int j=i+1;j<back;j++)
                {
                    if(pro[ready[i]].prio>pro[ready[i]].prio)
                    {
                        int t=ready[i];
                        ready[i]=ready[j];
                        ready[j]=t;
                    }
                }
            }
        }
    }
    printf("PRIORITY\n");
    printf("PID\tAT\tBT\tPRIO\tCT\tTAT\tWT\n");
    float total=0;
    for(int i=0;i<n;i++)
    {
        printf("%i\t%i\t%i\t%i\t%i\t%i\t%i\n",pro[i].id,pro[i].at,pro[i].bt,pro[i].prio,pro[i].ct,pro[i].tat,pro[i].wt);
        total+=pro[i].wt;
    }
    printf("\nAVG WT = %0.2f\n",total/n);
    printf("\n");
}


void rr(int n)
{
    reset(n);
    int count=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(pro[i].at>pro[j].at)
            {
                //swap
                node temp=pro[i];
                pro[i]=pro[j];
                pro[j]=temp; //swapped
            }
        }
    }
    int tq=2;
    int front=0, back=-1;
    int ready[20];
    for(int time=0;count<n;time++)
    {
        for(int i=0;i<n;i++)
        {
            if(pro[i].at==time)
            {
                back++;
                ready[back]=i;
            }
        }
        if(pro[ready[front]].rt>tq)
        {
            pro[ready[front]].rt-=tq;
            for(int i=time+1;i<time+tq;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(pro[j].at==i)
                    {
                        back++;
                        ready[back]=j;
                    }
                }
            }
            ready[++back]=ready[front];
            front++;
            time+=tq;
        }
        else
        {
            for(int i=time+1;i<time+pro[ready[front]].rt;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(pro[j].at==i)
                    {
                        back++;
                        ready[back]=j;
                    }
                }
            }
            time+=pro[ready[front]].rt-1;
            pro[ready[front]].rt=0;
        }
        if(pro[ready[front]].rt==0)
        {
            
            pro[ready[front]].ct=time+1;
            pro[ready[front]].tat = pro[ready[front]].ct - pro[ready[front]].at;
            pro[ready[front]].wt = pro[ready[front]].tat - pro[ready[front]].bt;
            front++;
            count++;
            if(front>back) continue;
            for(int i=front;i<back;i++)
            {
                for(int j=i+1;j<back;j++)
                {
                    if(pro[ready[i]].bt>pro[ready[i]].bt)
                    {
                        int t=ready[i];
                        ready[i]=ready[j];
                        ready[j]=t;
                    }
                }
            }
        }
    }
    printf("ROUND ROBIN\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    float total=0;
    for(int i=0;i<n;i++)
    {
        printf("%i\t%i\t%i\t%i\t%i\t%i\n",pro[i].id,pro[i].at,pro[i].bt,pro[i].ct,pro[i].tat,pro[i].wt);
        total+=pro[i].wt;
    }
    printf("\nAVG WT = %0.2f\n",total/n);
    printf("\n");
}

int main()
{
    int n=5;
    printf("Enter number of processes : ");
    scanf("%i",&n);
    printf("Enter AT, BT and PRIO of each process\n");
    //int n=5;
    for(int i=0;i<n;i++)
    {
        pro[i].id=i+1;
    }
    /*for(int i=0;i<n;i++)
    {
        scanf("%i",&pro[i].at);
        scanf("%i",&pro[i].bt);
        scanf("%i",&pro[i].prio);
        //scanf("%i %i",&pro[i].at,&pro[i].bt);
    }*/
   
    pro[0].at=0, pro[0].bt=2, pro[0].prio=0;
    pro[1].at=1, pro[1].bt=2, pro[1].prio=0;
    pro[2].at=5, pro[2].bt=3, pro[2].prio=0;
    pro[3].at=6, pro[3].bt=4, pro[3].prio=0;
    pro[4].at=6, pro[4].bt=4, pro[4].prio=0;
    printf("TEST\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    float total=0;
    for(int i=0;i<n;i++)
    {
        printf("%i\t%i\t%i\t%i\t%i\t%i\n",pro[i].id,pro[i].at,pro[i].bt,pro[i].ct,pro[i].tat,pro[i].wt);
        total+=pro[i].wt;
    }
    printf("\nAVG WT = %0.2f\n",total/n);
    printf("\n");
    //pro[3].at=6, pro[3].bt=4, pro[3].prio=0;
    fcfs(n);
    /*sjf(n);
    prio(n);
    rr(n);*/
    while(1)
    {
        printf("\n1.FCFS\n2.SJF\n3.ROUND ROBIN\n4.PRIORITY\n0.exit\nEnter a key : ");
        int key;
        scanf("%i",&key);
        switch(key)
        {
            case 0 : exit(0);
                break;
            case 1 : fcfs(n);
                break;
            case 2 : sjf(n);
                break;
            case 3 : rr(n);
                break;
            case 4 : prio(n);
                break;
            default : printf("Wrong input\n");
                break;
        }
    }
    

    
}
