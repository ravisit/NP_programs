#include<stdio.h>
#include<stdlib.h>
#define INFINITY 999
int main()
{
	int cost[20][20],d[20],i,j,n,root,pred[20],visited[20],mindistance,count,nextnode;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	printf("Enter cost matrix:(999 for infinity)\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
	printf("Enter the root node: ");
	scanf("%d",&root);
	
	for(i=0;i<n;i++)
    {
        d[i]=cost[root][i];
        pred[i]=root;
        visited[i]=0;
    }
	
    d[root]=0;
    visited[root]=1;
    count=1;

    while(count<n-1)
    {
        mindistance=INFINITY;
        
        for(i=0;i<n;i++)
            if(d[i]<mindistance&&!visited[i])
            {
                mindistance=d[i];
                nextnode=i;
            }
                        
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<d[i])
                    {
                        d[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }

    for(i=0;i<n;i++){
        if(i!=root)
        {
            printf("\nDistance of node %d= %d",i,d[i]);
            printf("\nPath= %d",i);
            
            j=i;
            do
            {
                j=pred[j];
                printf("<-%d",j);
            }while(j!=root);
        }
        printf("\n");
    }
	return 0;
}