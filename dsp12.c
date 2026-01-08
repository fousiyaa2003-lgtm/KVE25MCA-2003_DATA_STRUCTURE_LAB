#include<stdio.h>

int n, visited[10], G[10][10];

void DFS(int v)
{
    int i;
    printf("Visited %d\n", v);
    visited[v] = 1;
    for(i = 0; i < n; i++)
    {
        if(G[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

int main()
{
    int i, j, vertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter graph data in matrix form:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }
    
    for(i = 0; i < n; i++)
        visited[i] = 0;
        
    printf("Enter the starting vertex ");
    scanf("%d", &vertex);
    
    DFS(vertex);
    return 0;
}

