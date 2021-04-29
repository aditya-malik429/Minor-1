
#include <stdlib.h>
#include<stdio.h>
#define MAX 101
#define INFINITY 9999.000000

void dijkstra(double G[MAX][MAX],int n,int startnode,struct star arr[MAX])
{

    double cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;


    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];


    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }

    distance[startnode]=0;
    visited[startnode]=1;
    count=1;

    while(count<n-1)
    {
        mindistance=INFINITY;


        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }

        visited[nextnode]=1;
        for(i=0;i<n;i++)
            if(!visited[i])
                if(mindistance+cost[nextnode][i]<distance[i])
                {
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
        count++;
    }


    for(i=0;i<n;i++)
        if(i!=startnode)
        {
            if(distance[i]==INFINITY)
            {
                printf("\nDistance of node %d = Not Reachable",i);
            }
            else
            {
                printf("\nDistance of node %d = %lf",i,distance[i]);
            }
            printf("\nPath= %s",arr[i].s);

            j=i;
            do
            {
                j=pred[j];
                printf("<-------%s",arr[j].s);
            }while(j!=startnode);
            printf("\n");
        }
}