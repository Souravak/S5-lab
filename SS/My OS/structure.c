#include<stdio.h>
struct Node
{
    int x;
    int y;
    int z;
    int sum;
};
typedef struct Node node;
int main()
{
    int a=5,b=20,c=30;
    node kunjamma;
    kunjamma.x=a;
    kunjamma.y=b;
    kunjamma.z=c;
    kunjamma.sum=kunjamma.x+kunjamma.y+kunjamma.z;
    printf("\nKunjamma.x = %i",kunjamma.x);
    printf("\nKunjamma.y = %i",kunjamma.y);
    printf("\nKunjamma.z = %i",kunjamma.z);
    printf("\nKunjamma.sum = %i",kunjamma.sum);

}