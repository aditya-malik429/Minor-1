#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include "filehandler.c"
#include "Dijstra.c"
#include "BellmanFord.c"
#define MAX 101
#define INFINITY 9999


double euclidean_distance(float x1, float y1,float z1, float x2, float y2, float z2) {
    // Calculating distance
    return sqrt((pow(x2 - x1, 2) +  pow(y2 - y1, 2) + pow(z2 -z1, 2)) * 1.0);
}

int main()
{

    int i,j,start,end,n,edge[10000][2],k=0;
    double h[MAX],G[MAX][MAX];
    float max_dist;
    struct star arr[MAX];
    handler(arr);
    n=MAX;
    printf("Enter the max distance possible to scale (>4.5) in ly :");
    scanf("%f",&max_dist);
    //constructing adjacency matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                G[i][j]=0.00;
                continue;
            }
                //calculating Euclidean distance
            G[i][j]=euclidean_distance(arr[i].cor[0],arr[i].cor[1],arr[i].cor[2],arr[j].cor[0],arr[j].cor[1],arr[j].cor[2]);

            if(G[i][j]>max_dist || G[i][j]<0){
                //disconnect the nodes
                G[i][j]=0;
            }
            if(G[i][j]!=0){
                 edge[k][0]=i,edge[k++][1]=j;
            }
        }
    }

    start = 0;

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         printf("%lf ",G[i][j]);
    //     }
    //     printf("\n");
    // }


    clock_t t1;
    t1 = clock();
    dijkstra(G,n,start,arr);
    t1 = clock() - t1;
    float time_taken1 = ((float)t1)/CLOCKS_PER_SEC; // in seconds
    
    // clock_t t2;
    // t2 = clock();
    // Bellman_Ford(G,n,k,edge,arr);
    // t2 = clock() - t2;
    // float time_taken2 = ((float)t2)/CLOCKS_PER_SEC; // in seconds
    
    printf("dijkstra took %0.5f seconds to execute \n", time_taken1);
    // printf("Bellman Ford took %0.5f seconds to execute \n", time_taken2);
    
    
    return 0;
}
