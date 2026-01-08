#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int parent[MAX];

// Function to find the representative (root) of a set
int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

// Function to unite two sets
int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int vertex_count = 0;
    int cost_matrix[MAX][MAX];
    int edge_count = 0, count = 1;
    int sum_cost = 0, min_cost;
    int row_no, column_no, edge1, edge2;
    int row, column;

    printf("Implementation of Kruskal's Algorithm\n");
    printf("Enter total number of vertices: ");
    scanf("%d", &vertex_count);

    // Read the Weight Matrix
    printf("\nEnter the weight matrix:\n");
    for (row = 1; row <= vertex_count; row++) {
        for (column = 1; column <= vertex_count; column++) {
            scanf("%d", &cost_matrix[row][column]);
            
            // If input is 0 (no edge), replace with Infinity (999) 
            // to avoid picking it as a minimum edge
            if (cost_matrix[row][column] == 0) {
                cost_matrix[row][column] = 999;
            }
        }
    }

    edge_count = vertex_count - 1; // MST always has V-1 edges

    while (count <= edge_count) {
        min_cost = 999;

        // Find the edge with the minimum weight in the matrix
        for (row = 1; row <= vertex_count; row++) {
            for (column = 1; column <= vertex_count; column++) {
                if (cost_matrix[row][column] < min_cost) {
                    min_cost = cost_matrix[row][column];
                    edge1 = row_no = row;
                    edge2 = column_no = column;
                }
            }
        }

        // Check for cycles using Find
        row_no = find(row_no);
        column_no = find(column_no);

        // If no cycle, include edge in MST and perform Union
        if (uni(row_no, column_no)) {
            printf("\nEdge %d: (%d - %d) with cost : %d", count++, edge1, edge2, min_cost);
            sum_cost = sum_cost + min_cost;
        }

        // Mark the edge as used (Infinity) so it isn't picked again
        cost_matrix[edge1][edge2] = cost_matrix[edge2][edge1] = 999;
    }

    printf("\n\nMinimum cost = %d\n", sum_cost);
    return 0;
}
