#include <stdio.h>
#include <string.h>
struct pro
{
    int num, arr, prio, bur, comp, wait, turn, vis, rem;
};
int n;
struct pro p[50];
void sort()
{
    struct pro temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].arr > p[j + 1].arr)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
void sortn()
{
    struct pro temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].num > p[j + 1].num)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
void calc()
{
    float t = 0, nn = n, w = 0;
    for (int i = 0; i < n; i++)
    {
        p[i].turn = p[i].comp - p[i].arr;
        p[i].wait = p[i].turn - p[i].bur;
        t += p[i].turn;
        w += p[i].wait;
    }
    printf("Average Turn around time %.2f\n", t / nn);
    printf("Average waiting time %.2f\n", w / nn);
}
void fcfs()
{
    int co = p[0].arr;
    sort();
    for (int i = 0; i < n; i++)
    {
        if (p[i].arr <= co)
        {
            co += p[i].bur;
            p[i].comp = co;
        }
        else
        {
            co = p[i].arr;
            i--;
        }
    }
    calc();
    sortn();
    for (int i = 0; i < n; i++)
    {
        printf("%i %i\n", p[i].num, p[i].comp);
    }
}
void sjf()
{
    int co = p[0].arr;
    sort();
    for (int i = 0; i < n; i++)
        p[i].vis = 0;
    for (int i = 0; i < n;)
    {
        if (p[i].vis == 0)
        {
            if (p[i].arr <= co)
            {
                //co += p[i].bur;
                //p[i].comp = co;
                int mi = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (p[j].vis == 0 && p[j].bur < p[mi].bur && p[j].arr <= co)
                    {
                        mi = j;
                    }
                }
                co += p[mi].bur;
                p[mi].comp = co;
                p[mi].vis = 1;
            }
            else
            {
                co = p[i].arr;
            }
        }
        else
        {
            i++;
        }
    }
    calc();
    sortn();
    for (int i = 0; i < n; i++)
    {
        printf("%i %i\n", p[i].num, p[i].comp);
    }
}
void nprio()
{
    int co = p[0].arr;
    sort();
    for (int i = 0; i < n;)
    {
        if (p[i].vis == 0)
        {
            if (p[i].arr <= co)
            {
                //co += p[i].bur;
                //p[i].comp = co;
                int mi = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (p[j].vis == 0 && p[j].prio < p[mi].prio && p[j].arr <= co)
                    {
                        mi = j;
                    }
                }
                co += p[mi].bur;
                p[mi].comp = co;
                p[mi].vis = 1;
            }
            else
            {
                co = p[i].arr;
            }
        }
        else
        {
            i++;
        }
    }
    calc();
    sortn();
    for (int i = 0; i < n; i++)
    {
        printf("%i %i\n", p[i].num, p[i].comp);
    }
}
void srtf()
{
    int co = p[0].arr;
    sort();
    for (int i = 0; i < n; i++)
    {
        p[i].vis = 0;
        p[i].rem = p[i].bur;
    }
    for (int i = 0; i < n;)
    {
        if (p[i].rem != 0)
        {
            if (p[i].arr <= co)
            {
                int mi = i;
                for (int j = 0; j < n; j++)
                {
                    if (p[j].rem != 0 && p[j].rem < p[mi].rem && p[j].arr <= co)
                    {
                        mi = j;
                    }
                }
                int check = 0;
                for (int k = 1; k <= p[mi].rem; k++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (p[j].rem != 0 && co + k >= p[j].arr && p[j].rem < p[mi].rem - k)
                        {
                            check = 1;
                            p[mi].rem -= k;
                            co += k;
                            break;
                        }
                    }
                    if (check)
                    {
                        break;
                    }
                }
                if (check == 0)
                {

                    co += p[mi].rem;
                    p[mi].rem = 0;
                    p[mi].comp = co;
                }
                for (int j = 0; j < n; j++)
                {
                    if (p[j].rem != 0)
                    {
                        mi = j;
                        break;
                    }
                }
            }
            else
            {
                co = p[i].arr;
            }
        }
        else
        {
            i++;
        }
    }
    calc();
    sortn();
    for (int i = 0; i < n; i++)
    {
        printf("%i %i\n", p[i].num, p[i].comp);
    }
}
void prio()
{
    int co = p[0].arr;
    sort();
    for (int i = 0; i < n; i++)
    {
        p[i].vis = 0;
        p[i].rem = p[i].bur;
    }
    for (int i = 0; i < n;)
    {
        if (p[i].rem != 0)
        {
            if (p[i].arr <= co)
            {
                int mi = i;
                for (int j = 0; j < n; j++)
                {
                    if (p[j].rem != 0 && p[j].prio < p[mi].prio && p[j].arr <= co)
                    {
                        mi = j;
                    }
                }
                int check = 0;
                for (int k = 1; k <= p[mi].rem; k++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (p[j].rem != 0 && co + k >= p[j].arr && p[j].prio < p[mi].prio)
                        {
                            check = 1;
                            p[mi].rem -= k;
                            co += k;
                            break;
                        }
                    }
                    if (check)
                    {
                        break;
                    }
                }
                if (check == 0)
                {

                    co += p[mi].rem;
                    p[mi].rem = 0;
                    p[mi].comp = co;
                }
                for (int j = 0; j < n; j++)
                {
                    if (p[j].rem != 0)
                    {
                        mi = j;
                        break;
                    }
                }
            }
            else
            {
                co = p[i].arr;
            }
        }
        else
        {
            i++;
        }
    }
    calc();
    sortn();
    for (int i = 0; i < n; i++)
    {
        printf("%i %i\n", p[i].num, p[i].comp);
    }
}
int tq;
void rb()
{
    int q[100];
    memset(q, -1, sizeof(q));
    printf("Enter the time quantum\n");
    scanf("%i", &tq);
    sort();
    int ptr = 0;
    int ptr2 = 1;
    q[ptr] = 0;
    int co = p[0].arr;
    for (int i = 0; i < n; i++)
    {
        p[i].vis = 0;
        p[i].rem = p[i].bur;
    }

    while (q[ptr] != -1)
    {
        int ind = q[ptr];
        p[ind].vis = 1;
        int v = tq;
        if (tq > p[ind].rem)
        {
            v = p[ind].rem;
        }
        for (int k = 1; k <= v; k++)
        {
            for (int j = 0; j < n; j++)
            {
                if (co + k >= p[j].arr && p[j].vis != 1)
                {
                    p[j].vis = 1;
                    q[ptr2++] = j;
                }
            }
        }
        //ptr++;
        co += v;

        if (p[ind].rem <= tq)
        {
            //co+=p[ind].rem;
            p[ind].comp = co;
            p[ind].rem = 0;
        }
        else
        {
            p[ind].rem -= v;
            //co+=v;
            q[ptr2++] = ind;
        }
        ptr++;
    }

    calc();
    //sortn();
    for (int i = 0; i < n; i++)
    {
        printf("%i %i\n", p[i].num, p[i].comp);
    }
    for (int i = 0; i < ptr2; i++)
    {
        printf(" %i ", p[q[i]].num+1);
    }
    printf("\n");
}

int time, rcheck;
void rbb()
{
    rcheck = 0;
    int q[100];
    memset(q, -1, sizeof(q));
    //memset(qq, -1, sizeof(qq));
    printf(" Enter the time instant \n");
    scanf("%i", &time);
    sort();
    int ptr = 0;
    int ptr2 = 1;
    q[ptr] = 0;
    //qq[ptr]=p[0].num;
    int co = p[0].arr;
    for (int i = 0; i < n; i++)
    {
        p[i].vis = 0;
        p[i].comp = -1;
        p[i].rem = p[i].bur;
    }

    int tt = co;
    while (q[ptr] != -1)
    {
        int ind = q[ptr];
        p[ind].vis = 1;
        int v = tq;
        if (tq > p[ind].rem)
        {
            v = p[ind].rem;
        }

        for (int k = 1; k <= v; k++, tt++)
        {
            if (tt <= time)
            {
                for (int j = 0; j < n; j++)
                {
                    if (co + k >= p[j].arr && p[j].vis != 1)
                    {
                        p[j].vis = 1;
                        q[ptr2++] = j;
                    }
                }
                if (tt == time)
                {
                    printf("Process in execution is %i\n", p[q[ptr]].num + 1);
                    printf("Process in ready queue are:\n");
                    for (int i = ptr + 1; i < ptr2; i++)
                    {
                        printf(" %i ", p[q[i]].num + 1);
                    }
                    printf("\n");
                    rcheck = 1;
                    break;
                }
            }

            printf("\n");
        }

        if (rcheck)
        {
            break;
        }
        co += v;
        if (p[ind].rem <= tq)
        {
            //co+=p[ind].rem;
            p[ind].comp = co;
            p[ind].rem = 0;
        }
        else
        {
            p[ind].rem -= v;
            //co+=v;
            q[ptr2++] = ind;
        }
        tt = co;
        ptr++;
    }
    sortn();
    printf("Completed proceesses are:\n");
    for (int i = 0; i < n; i++)
    {
        if (p[i].comp != -1)
        {
            printf(" %i ", i + 1);
        }
    }
    printf("\n");
    // //calc();
    // sortn();
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%i %i\n", p[i].num, p[i].comp);
    // }
}
int main()
{
    printf("Enter the number of processes\n");
    scanf("%i", &n);
    printf("Enter the arrival time,burst time and priority of each processes\n");
    //struct pro p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].num = i;
        scanf("%i %i %i", &p[i].arr, &p[i].bur, &p[i].prio);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%i %i %i %i\n", p[i].num, p[i].arr, p[i].bur, p[i].prio);
    }
    printf("FCFS\n");
    fcfs();
    printf("SJF\n");
    sjf();
    printf("Nprio\n");
    nprio();
    printf("SRTF\n");
    srtf();
    printf("prio\n");
    prio();
    printf("rb\n");
    rb();
    int k = 5;
    while (1)
    {
        rbb();
    }
}
/*
0 8 3
5 2 4
1 7 9
6 3 7
8 5 8*/