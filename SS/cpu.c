#include<stdio.h>
#include<stdlib.h>
int n=5;
struct Node
{
    int id;
    int at;
    int bt;
    int btori;
    int tat;
    int ct;
    int wt;
    int prio;
    int visit;
};
typedef struct Node node;
node pro[5];



/*void fcfs()
{
    int count=0;
    int front=0,temp;
    int ready[10],back=-1;
    printf("Working fine");
    for(int i=0;i<n;i++) pro[i].btori=pro[i].bt;
    printf("Working fine");
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
    printf("Working");
    for(int time=0;time!=-1;time++)
    {
        for(int i=0;i<n;i++)
        {
            if(pro[i].at==time)
            {
                back++;
                ready[back]=i;
            }
        }
        if(pro[ready[front]].bt>0) pro[ready[front]].bt--;
        if(pro[ready[front]].bt==0)
        {
            pro[ready[front]].ct=time;
            pro[ready[front]].tat=pro[ready[front]].ct-pro[ready[front]].at;
            pro[ready[front]].wt=pro[ready[front]].tat-pro[ready[front]].bt;
            front++;
            count++;
            if(count==5) break;
        }
    }
    printf("FCFS\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("%i\t%i\t%i\t%i\t%i\t%i\n",pro[i].id,pro[i].at,pro[i].btori,pro[i].ct,pro[i].tat,pro[i].wt);
    }
    printf("\n");
}*/

void sjf()
{
    for(int i=0;i<n;i++)
    {
        pro[i].btori=pro[i].bt;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(pro[i].at>pro[j].at)
            {
                node temp=pro[i];
                pro[i]=pro[j];
                pro[j]=temp;
            }
        }
    }
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("%i\t%i\t%i\t%i\t%i\t%i\n",pro[i].id,pro[i].at,pro[i].btori,pro[i].ct,pro[i].tat,pro[i].wt);
    }
    printf("\n");
    /*for(int i=0;i<n;i++)
    {
        printf("%i ",pro[i].at);
    }*/
    int count=0;
    int ready[100];
    int front=0,back=-1;
    for(int time=0;time<10;time++)
    {
        printf("\nTIME = %i ",time);
        printf("READY :");
        
        for(int i=0;i<n;i++)
        {
            if(pro[i].at==time)
            {
                back++;
                ready[back]=i;  
            }
        }
        for(int j=front;j<=back;j++)
        {
            printf("%i ",pro[ready[j]].bt);
        }
        if(pro[ready[front]].bt>0) pro[ready[front]].bt--;
        
        //printf("----%i------",pro[ready[0]].at);
        
        
        
    }
}

int main()
{
    /*int n;
    printf("Enter number of processes : ");
    scanf("%i",&n);
    node pro[n];
    printf("Enter AT, BT of each process\n");
    */
    n=5;
    printf("Working1");
    for(int i=0;i<n;i++)
    {
        pro[i].id=i+1;
        //scanf("%i %i",&pro[i].at,&pro[i].bt);
    }
   
    pro[0].at=1, pro[0].bt=8;
    pro[1].at=2, pro[1].bt=3;
    pro[2].at=7, pro[2].bt=5;
    pro[3].at=5, pro[3].bt=10;
    pro[4].at=3, pro[4].bt=2;
    //fcfs();
    sjf();

    
}