#include <stdio.h>

int n, visited[10], queue[10], front = -1, rear = -1;
int graph[10][10];

void BFS(int v) {
    int i;
    visited[v] = 1;
    queue[++rear] = v;
    printf("%d\t", v);

    while (front < rear) {
        front++;
        int current = queue[front];
        
        // Check all adjacent vertices
        for (i = 0; i < n; i++) {
            // If there is an edge and it hasn't been visited yet
            if (graph[current][i] == 1 && visited[i] == 0) {
                queue[++rear] = i; // Enqueue the neighbor
                visited[i] = 1; // Mark as visited
                printf("%d\t", i); // Print it
            }
        }
    }
}

int main() {
    int vertex, i, j;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize visited and queue arrays
    for (int k = 0; k < n; k++) {
        visited[k] = 0;
        queue[k] = 0;
    }

    printf("Enter the graph data in matrix form: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nThe matrix is: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &vertex);

    printf("BFS traversal starting from vertex %d\n", vertex);
    BFS(vertex);
    
    return 0;
}
