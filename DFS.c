#include<stdio.h>
#define MAX 101
void func(int i,double G[MAX][MAX],int visited[MAX],struct star arr[101])
{
    int j;
    printf("\n%s",arr[i].s);
    visited[i]=1;

    for(j=0;j<MAX;j++)
       if(!visited[j]&&G[i][j]!=0)
            func(j,G,visited,arr);

}

void dfs(double G[MAX][MAX],struct star arr[101])
{   int i;
    int visited[MAX];
    
    for(i=0;i<MAX;i++){
        visited[i]=0;
    }

    func(0,G,visited,arr);
}
 
