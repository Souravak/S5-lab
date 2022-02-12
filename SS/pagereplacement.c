#include <stdio.h>
#include <stdlib.h>
int n, a[40], f, c;
void fifo()
{
    int frame[f];
    for (int i = 0; i < f; i++)
    {
        frame[i] = -1;
    }
    int count = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        int fcheck = 0;
        for (int k = 0; k < f; k++)
            if (a[i] == frame[k])
                fcheck = 1;
        if (fcheck)
        {
            int ui = 9;
        }
        else
        {
            frame[j] = a[i];

            j = (j + 1) % f;
            count++;
        }
    }

    printf("\nPage fault : %i", count);
}
void lfu()
{
    int frame[10], hit = 0, count[50], time[50];
    int i, j, page, flag, least, minTime, temp;

    for (i = 0; i < f; i++)
    {
        frame[i] = -1;
    }
    for (i = 0; i < 50; i++)
    {
        count[i] = 0;
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        count[a[i]]++;
        time[a[i]] = i;
        flag = 1;
        least = frame[0];
        for (j = 0; j < f; j++)
        {
            if (frame[j] == -1 || frame[j] == a[i])
            {
                if (frame[j] != -1)
                {
                    hit++;
                }
                flag = 0;

                frame[j] = a[i];
                break;
            }
            if (count[least] > count[frame[j]])
            {
                least = frame[j];
            }
        }
        if (flag)
        {
            minTime = 50;
            for (j = 0; j < f; j++)
            {
                if (count[frame[j]] == count[least] && time[frame[j]] < minTime)
                {
                    temp = j;
                    minTime = time[frame[j]];
                }
            }
            count[frame[temp]] = 0;
            frame[temp] = a[i];
        }
    }
    printf("\nPage fault = %d", n - hit);
}

void lru()
{
    int frame[f];
    for (int i = 0; i < f; i++)
    {
        frame[i] = -1;
    }
    int count = 0, e;
    for (int i = 0; i < n; i++)
    {
        int fd = 0;

        for (int j = 0; j < f; j++)
        {

            if (a[i] == frame[j])
            {
                fd = 1;
                break;
            }
        }
        if (fd == 0)
        {
            frame[count++] = a[i];
            if (count == f)
            {
                e = i;
                break;
            }
        }
    }
    for (int i = e + 1; i < n; i++)
    {
        int fd = 0;
        for (int j = 0; j < f; j++)
        {

            if (a[i] == frame[j])
            {
                fd = 1;
                break;
            }
        }
        if (fd == 0)
        {

            if (i == n - 1)
            {
                count++;
            }
            else
            {
                int s = 0, si = 0, t = 0;
                for (int k = 0; k < f; k++)
                {

                    t = 0;
                    int j;
                    for (j = i - 1; j >= 0; j--)
                    {

                        t++;
                        if (a[j] == frame[k])
                        {
                            break;
                        }
                    }
                    if (s < t)
                    {

                        s = t;
                        si = k;
                    }
                }
                // printf("wsda");
                frame[si] = a[i];
                count++;
            }
        }
    }
    printf("\npage fault : %i", count);
}
int main(int argc, char const *argv[])
{
    printf("Enter the length of reference string\n");
    scanf("%i", &n);
    printf("Enter the Reference string\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &a[i]);
    }
    printf("Enter the number of frames\n");
    scanf("%i", &f);
    while (1)
    {
        printf("\n");
        printf("1.FIFO\n");
        printf("2.LRU\n");
        printf("3.LFU\n");
        printf("4.Exit\n");
        int ch;
        printf("\nInput your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            fifo();
            break;
        case 2:
            lru();
            break;
        case 3:
            lfu();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Please input a valid choice.\n");
        }
    }
    return 0;
}
