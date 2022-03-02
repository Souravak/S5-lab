#include <stdio.h>
#include <stdlib.h>
void print(int n, int m, int a[][m])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("P%i\t", i);
        for (j = 0; j < m; j++)
        {
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }
}
void printav(int a[], int m)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        printf("%i ", a[i]);
    }
}
int safe_test(int n, int m, int alloc_mat[][m], int need_mat[][m], int available[], int safe_1[], int safe_2[], int safe_a, int safe_b)
{
    int process_status[n];
    int avail_temp[m];
    int i, j, k;
    int x = 0;
    safe_a = 0, safe_b = 0;
    int done_process = 0;
    int flag = 0;
    for (i = 0; i < n; i++)
    {
        process_status[i] = 0;
    }
    for (i = 0; i < m; i++)
    {
        avail_temp[i] = available[i];
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            flag = 0;
            if (process_status[i] == 0)
            {
                flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (avail_temp[j] < need_mat[i][j])
                    {
                        flag = 1;
                    }
                }
                if (flag == 0)
                {
                    for (j = 0; j < m; j++)
                    {
                        avail_temp[j] += alloc_mat[i][j];
                    }
                    process_status[i] = 1;
                    done_process++;
                    safe_1[x++] = i;
                }
            }
        }
    }
    if (done_process == n)
    {
        safe_a = 1;
    }
    /////////////////////////////////////////
    x = 0;
    done_process = 0;
    for (i = 0; i < n; i++)
    {
        process_status[i] = 0;
    }
    for (i = 0; i < m; i++)
    {
        avail_temp[i] = available[i];
    }
    for (k = 0; k < n; k++)
    {
        for (i = n - 1; i >= 0; i--)
        {
            if (process_status[i] == 0)
            {
                flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (avail_temp[j] < need_mat[i][j])
                    {
                        flag = 1;
                    }
                }
                if (flag == 0)
                {
                    for (j = 0; j < m; j++)
                    {
                        avail_temp[j] += alloc_mat[i][j];
                    }
                    process_status[i] = 1;
                    done_process++;
                    safe_2[x++] = i;
                }
            }
        }
    }
    if (done_process == n)
    {
        safe_b = 1;
    }
    if (safe_a == 1 || safe_b == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n=5, m=3;
    // printf("Enter the number of processes : ");
    // scanf("%i", &n);
    // printf("Enter the number of resources : ");
    // scanf("%i", &m);
    // int alloc_mat[n][m];
    // int max_mat[n][m];
    // int available[m];
    // int need_mat[n][m];
    int safe_1[n], safe_2[n];
    int safe_a = 0, safe_b = 0;
    int i, j;
    int opt;
    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j < m; j++)
    //     {
    //         scanf("%i", &alloc_mat[i][j]); //alloc
    //     }
    //     for (j = 0; j < m; j++)
    //     {
    //         scanf("%i", &max_mat[i][j]); //max
    //     }
    // }
    // for (i = 0; i < m; i++)
    // {
    //     scanf("%i", &available[i]); //available array
    // }
    int available[3]={3,3,2}; //Available
    int alloc_mat[5][3]={{2,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};//P0 P1 P2 P3 P4
    int max_mat[5][3]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}}; // P0 P1 P2 P3 P4
    int need_mat[5][3];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need_mat[i][j] = max_mat[i][j] - alloc_mat[i][j];
        }
    }
    printf("Allocation Matrix\n");
    print(n, m, alloc_mat);
    printf("Max Matrix\n");
    print(n, m, max_mat);
    printf("Need Matrix\n");
    print(n, m, need_mat);
    printf("Available : ");
    printav(available, m);


    int result = safe_test(n, m, alloc_mat, need_mat, available, safe_1, safe_2, safe_a, safe_b);
    if (result != 0)
    {
        printf("\nSafe sequence found\n");
        printf("Safe sequence is : ");
        for (i = 0; i < n; i++)
        {
            printf("P%i ", safe_1[i]);
        }
        printf("\nAnother safe sequence is : ");
        for (i = 0; i < n; i++)
        {
            printf("P%i ", safe_2[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nDeadLock occured!\n");
        exit(0);
    }
    while (1)
    {
        printf("Do you want to make additional request?\n");
        printf("1.Yes\n");
        printf("2.No\n");
        printf("Enter an option key : ");
        scanf("%i", &opt);
        if (opt == 1)
        {
            printf("List of processes available : ");
            for (i = 0; i < n; i++)
            {
                printf("P%i ", i);
            }
            printf("\nSelect a process number : ");
            int process_num;
            int req_resourse[m];
            scanf("%i", &process_num);
            printf("Enter additional resourse request for P%i : ", process_num);
            for (i = 0; i < m; i++)
            {
                scanf("%i", &req_resourse[i]);
            }
            
            for (i = 0; i < m; i++)
            {
                if (req_resourse[i] > need_mat[process_num][i])
                {
                    printf("Error occured\n");
                    exit(0);
                }
            }
            for (i = 0; i < m; i++)
            {
                if (req_resourse[i] > available[i])
                {
                    printf("Resource unavailable\n");
                    exit(0);
                }
            }
            for (i = 0; i < m; i++)
            {
                available[i] -= req_resourse[i];
                alloc_mat[process_num][i] += req_resourse[i];
                need_mat[process_num][i] -= req_resourse[i];
            }
            result = safe_test(n, m, alloc_mat, need_mat, available, safe_1, safe_2, safe_a, safe_b);
            if (result != 0)
            {
                printf("\nSafe sequence found\n");
                printf("Safe sequence is : ");
                for (i = 0; i < n; i++)
                {
                    printf("P%i, ", safe_1[i]);
                }
                printf("\nAnother safe sequence is : ");
                for (i = 0; i < n; i++)
                {
                    printf("P%i, ", safe_2[i]);
                }
                printf("\n");
            }
            else
            {
                printf("\nDeadLock occured!\n");
                exit(0);
            }
        }
        else
        {
            exit(0);
        }
    }
}