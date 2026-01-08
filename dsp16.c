#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Graph {
    int V;
    int adj[MAX][MAX];
} Graph;

Graph *createGraph(int V) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph *graph, int u, int v) {
    graph->adj[u][v] = 1;
}

void DFS(Graph *graph, int v, int visited[]) {
    visited[v] = 1;
    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[v][i] == 1 && visited[i] == 0) {
            DFS(graph, i, visited);
        }
    }
}

int isStronglyConnected(Graph *graph) {
    // Step 1: DFS from first vertex
    int visited[MAX] = {0};
    DFS(graph, 0, visited);
    
    // Check if all nodes were visited
    for (int i = 0; i < graph->V; i++) {
        if (visited[i] == 0) {
            return 0;
        }
    }

    // Step 2: Create Transpose Graph
    Graph *transposeGraph = createGraph(graph->V);
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            if (graph->adj[i][j] == 1) {
                // Reverse the direction: if i->j exists, add j->i
                addEdge(transposeGraph, j, i);
            }
        }
    }

    // Step 3: DFS on Transpose Graph from first vertex
    int visitedTranspose[MAX] = {0};
    DFS(transposeGraph, 0, visitedTranspose);

    // Check if all nodes were visited in transpose
    for (int i = 0; i < graph->V; i++) {
        if (visitedTranspose[i] == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    Graph *graph = createGraph(V);

    int E;
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        int u, v;
        printf("Enter edge %d (u, v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    if (isStronglyConnected(graph)) {
        printf("The graph is strongly connected\n");
    } else {
        printf("The graph is not strongly connected\n");
    }

    return 0;
}

