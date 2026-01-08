#include <stdio.h>
#include <stdlib.h>

int s[100], j, res[100]; // Global variables for visited array (s), result index (j), and result array (res)

// Function to perform DFS
void dfs(int u, int n, int a[][100]) {
    int v;
    s[u] = 1; // Mark node u as visited
    for (v = 0; v < n; v++) {
        // If there is an edge from u to v AND v is not visited
        if (a[u][v] == 1 && s[v] == 0) {
            dfs(v, n, a);
        }
    }
    res[j++] = u; // Store the node in result array after processing all neighbors
}

// Function to generate a random Directed Acyclic Graph (DAG)
void AdjacencyMatrix(int a[][100], int n) {
    int i, j;
    // Initialize matrix to 0
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }

    // Create random edges while preventing cycles
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            a[i][j] = rand() % 2; // Randomly assign 0 or 1
            a[j][i] = 0; // Ensure no back-edge to keep it Acyclic (DAG)
        }
    }
}

// Wrapper function to manage the topological sort process
void topological_order(int n, int a[][100]) {
    int i, u;
    // Initialize visited array
    for (i = 0; i < n; i++) {
        s[i] = 0;
    }
    j = 0; // Initialize result index
    
    // Iterate through all nodes to handle disconnected components
    for (u = 0; u < n; u++) {
        if (s[u] == 0) {
            dfs(u, n, a);
        }
    }
}

int main() {
    int a[100][100], n, i, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    AdjacencyMatrix(a, n); // Generate the random graph

    printf("\nAdjacency Matrix of the graph: \n");
    for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++) {
            printf("%d ", a[i][k]);
        }
        printf("\n");
    }

    printf("\nIn Topological order: \n");
    topological_order(n, a);

    // Print the result array in reverse order
    for (i = j - 1; i >= 0; i--) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}

