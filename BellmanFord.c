#define INFINITY 9999
#define MAX 101
void Bellman_Ford(double G[101][101] , int V, int E, int edge[10000][2],struct star arr[MAX])
{
    int i,u,v,k,S=1,flag=1,parent[101];
    double distance[101];
    for(i=0;i<V;i++)
        distance[i] = INFINITY , parent[i] = -1 ;
    distance[S-1]=0.00 ;
    for(i=0;i<V-1;i++)
    {
        for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                distance[v] = distance[u] + G[u][v] , parent[v]=u ;
        }
    }
    for(k=0;k<E;k++)
    {
        u = edge[k][0] , v = edge[k][1] ;
        if(distance[u]+G[u][v] < distance[v])
            flag = 0 ;
    }
    if(flag)
        for(i=0;i<V;i++)
            if (distance[i]==INFINITY)
                printf("Vertex %s -> cost = Not Reachable parent = %d\n",arr[i].s,parent[i+1]);
            else
                printf("Vertex %s -> cost = %lf parent = %d\n",arr[i].s,distance[i],parent[i]+1);

}