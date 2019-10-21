#include<stdio.h>
#define M 50

/*
** Program to implement 0-1 knapsack problem
** Made by - Abhishek Chand
*/

typedef struct item{
	int no;
	int v;
	int w;
}item;

int V[M][M];

int get_max(int a, int b)
{
	if(a>=b)
		return a;
	else
		return b; 
}

void printPick(item I[],int i,int j)
{
	while(i>0 && j>0)
	{
		if(V[i][j]!=V[i-1][j])
		{
			printf("\n%d %d %d",I[i].no,I[i].v,I[i].w);
			j=j-I[i].w;
			i=i-1;
		}
		else
			i=i-1;
	}
}

void knapsack(item I[],int n,int W)
{   
    int i,j,tp=0,tv;
	for(i=0;i<=n;i++)
		V[i][0]=0;
	for(j=1;j<=W;j++)
		V[0][j]=0;
		
	printf("Output:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=W;j++)
		{
			if(I[i].w>j)
				V[i][j]=V[i-1][j];
			else
				V[i][j]=get_max(V[i-1][j],I[i].v+V[i-1][j-I[i].w]);	
			printf("%d\t",V[i][j]);	
		}
		printf("\n");
	}
	
	printf("------");
	printf("\nMax Value = %d",V[n][W]);
	printf("\nItems Picked:");
	printPick(I,n,W);
	
	
}

int main()
{
	int i,j,n,W;
	printf("\nNo. of items: ");
	scanf("%d",&n);
	item I[n+1],temp;
	printf("\nEnter the value and weight of items: ");
	for(i=1;i<=n;i++)
	{
	    I[i].no=i;
	    printf("\nItem %d: ",i);
	   	scanf("%d %d",&I[i].v,&I[i].w);
	}
	printf("\nKnapsack capacity: ");
	scanf("%d",&W);
	
	knapsack(I,n,W);
	return 0;
}
