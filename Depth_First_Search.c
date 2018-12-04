//DFS recursively
#include<stdio.h>
int n;
int visited[20] = {0};

/* void DFS(vertex v){
    visited[vertex]  = true;
    for each w adjacent to v
        if (!visited[w])
            DFS(w);
*/

void DFS(int a[n][n],int v){
    int i;
    visited[v] = 1;
    printf("%d ",v);
    for(i=0;i<n;i++)
        if(a[v][i] == 1 && !visited[i])
            DFS(a,i);
}

int main(){
    int i,j,s;
    printf("Enter how many points are there in your graph:\n");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter the adjacency list of graph\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    printf("Enter the source vertex\n");
    scanf("%d",&s);

    printf("The Depth First Search for your graph is \n");
    DFS(a,s);
    return 0;
}
