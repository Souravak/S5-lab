#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int file[50],start[50],len[50],block[10][10],n;
int st,l;

void clear()
{
	for(int i=0;i<50;i++)
	{
		file[i]=0;
	}
}

void sequential()
{
	clear();
	int i=0,k,flag;
	printf("\nno of files: ");
	scanf("%d",&n);
	while(i<n)
	{
		flag=0;
		printf("starting block and length of file %d: ",i+1);
		scanf("%d %d",&st,&l);
		for(k=st;k<st+l;k++)
			if(file[k]==0) flag++;
		if(flag==l)
		{
			for(k=st;k<st+l;k++)
				file[k]=1;
			start[i]=st;
			len[i]=l;
			i++;
		}
		else
		{
			printf("File %d could not be allocated.\n",i+1);
		}
	}
	printf("\nFILE\n");
	for(i=0;i<n;i++)
	{
		if(start[i]!=-1)
			printf("%d\t%d\tto\t%d\n",i+1,start[i],start[i]+len[i]);
	}
}

void indexed()
{
	clear();
	int i=0,k,flag;
	printf("\nInput the number of files: ");
	scanf("%d",&n);
	while(i<n)
	{
		flag=0;
		printf("index block and length of file %d: ",i+1);
		scanf("%d %d",&st,&l);
		printf("blocks stored in index block of file %d:-\n",i+1);
		for(k=0;k<l;k++)
		{
			scanf("%d",&block[i][k]);
			if(file[block[i][k]]==0) flag++;
		}
		if(file[st]==0) flag++;
		if(flag==l+1)
		{
			for(k=0;k<l;k++)
				file[block[i][k]]=1;
			file[st]=1;
			start[i]=st;
			len[i]=l;
			i++;
		}
		else
		{
			printf("File %d could not be allocated.\n",i+1);
		}
	}
	printf("\nFILE\t\n");
	for(i=0;i<n;i++)
	{
		if(start[i]!=-1)
		{
			printf("%d\t%d\t\t",i+1,start[i]);
			for(k=0;k<len[i];k++)
				printf("%d ",block[i][k]);
			printf("\n");
		}
	}
}

void linked()
{
	clear();
	int i=0,k,flag;
	printf("\nnumber of files: ");
	scanf("%d",&n);
	while(i<n)
	{
		flag=0;
		printf("start block and length of file %d: ",i+1);
		scanf("%d %d",&st,&l);
		printf("remaining blocks of file %d:-\n",i+1);
		for(k=0;k<l-1;k++)
		{
			scanf("%d",&block[i][k]);
			if(file[block[i][k]]==0) flag++;
		}
		if(file[st]==0) flag++;
		if(flag==l)
		{
			for(k=0;k<l-1;k++)
				file[block[i][k]]=1;
			file[st]=1;
			start[i]=st;
			len[i]=l;
			i++;
		}
		else
		{
			printf("File %d could not be allocated.\n",i+1);
		}
	}
	printf("\nFILE\t\n");
	for(i=0;i<n;i++)
	{
		if(start[i]!=-1)
		{
			printf("%d\t%d\t\t",i+1,start[i]);
			for(k=0;k<len[i]-2;k++)
				printf("%d->",block[i][k]);
			printf("%d\n",block[i][k]);
		}
	}
}

void main()
{
	
	while(1)
	{
		printf("\n");
		printf("1.Sequential\n");
		printf("2.Indexed\n");
		printf("3.Linked\n");
		printf("4.Exit\n");
		int ch;
		printf("\nInput your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: sequential(); break;
			case 2: indexed(); break;
			case 3: linked(); break;
			case 4: exit(0); break;
			default:printf("Please input a valid choice.\n");
		}
	}
}
