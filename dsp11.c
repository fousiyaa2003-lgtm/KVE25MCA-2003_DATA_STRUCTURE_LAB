#include <stdio.h>
#include <stdlib.h>

enum NodeColor { RED, BLACK };

struct rbNode {
    int data, color;
    struct rbNode *link[2]; // link[0] is left, link[1] is right
};

struct rbNode *root = NULL;

// Function to create a new node
struct rbNode *createNode(int data) {
    struct rbNode *newnode = (struct rbNode *)malloc(sizeof(struct rbNode));
    newnode->data = data;
    newnode->color = RED; // New nodes are always inserted as RED
    newnode->link[0] = newnode->link[1] = NULL;
    return newnode;
}

// Function to insert a node
void insertion(int data) {
    struct rbNode *stack[98], *ptr, *newnode, *xPtr, *yPtr;
    int dir[98], ht = 0, index;
    ptr = root;

    // Root is NULL case
    if (!root) {
        root = createNode(data);
        root->color = BLACK;
        return;
    }

    // Standard BST Insertion logic
    struct rbNode *current = root;
    stack[ht] = root;
    dir[ht++] = 0; // dummy value for root
    
    while (ptr != NULL) {
        if (ptr->data == data) {
            printf("Duplicates Not Allowed\n");
            return;
        }
        index = (data > ptr->data) ? 1 : 0;
        stack[ht] = ptr;
        dir[ht++] = index;
        ptr = ptr->link[index];
    }

    // Link the new node
    stack[ht - 1]->link[index] = newnode = createNode(data);
    
    // Rebalancing Loop (Fixing Red-Red Conflicts)
    while (ht >= 3 && stack[ht - 1]->color == RED) {
        if (dir[ht - 2] == 0) { // Parent is left child of Grandparent
            yPtr = stack[ht - 2]->link[1]; // Uncle is right child
            
            // Case 1: Uncle is RED -> Recolor
            if (yPtr != NULL && yPtr->color == RED) {
                stack[ht - 2]->color = RED;
                stack[ht - 1]->color = yPtr->color = BLACK;
                ht = ht - 2; // Move up the tree
            } 
            else { // Case 2 & 3: Uncle is BLACK or NULL -> Rotate
                if (dir[ht - 1] == 0) { // Left-Left Case
                    yPtr = stack[ht - 1]; 
                } else { // Left-Right Case
                    xPtr = stack[ht - 1];
                    yPtr = xPtr->link[0];
                    xPtr->link[0] = yPtr->link[1];
                    yPtr->link[1] = xPtr;
                    stack[ht - 2]->link[0] = yPtr;
                }
                
                // Final rotation for Left-Left
                xPtr = stack[ht - 2];
                xPtr->color = RED;
                yPtr->color = BLACK;
                xPtr->link[0] = yPtr->link[1];
                yPtr->link[1] = xPtr;
                
                if (xPtr == root) {
                    root = yPtr;
                } else {
                    stack[ht - 3]->link[dir[ht - 3]] = yPtr;
                }
                break;
            }
        } 
        else { // Parent is right child of Grandparent
            yPtr = stack[ht - 2]->link[0]; // Uncle is left child
            
            // Case 1: Uncle is RED -> Recolor
            if (yPtr != NULL && yPtr->color == RED) {
                stack[ht - 2]->color = RED;
                stack[ht - 1]->color = yPtr->color = BLACK;
                ht = ht - 2;
            } 
            else { // Case 2 & 3: Uncle is BLACK or NULL -> Rotate
                if (dir[ht - 1] == 1) { // Right-Right Case
                    yPtr = stack[ht - 1];
                } else { // Right-Left Case
                    xPtr = stack[ht - 1];
                    yPtr = xPtr->link[1]; // Typo fix from image logic
                    xPtr->link[1] = yPtr->link[0];
                    yPtr->link[0] = xPtr;
                    stack[ht - 2]->link[1] = yPtr;
                }

                // Final rotation for Right-Right
                xPtr = stack[ht - 2];
                yPtr->color = BLACK;
                xPtr->color = RED;
                xPtr->link[1] = yPtr->link[0];
                yPtr->link[0] = xPtr;
                
                if (xPtr == root) {
                    root = yPtr;
                } else {
                    stack[ht - 3]->link[dir[ht - 3]] = yPtr;
                }
                break;
            }
        }
    }
    root->color = BLACK; // Root must always be black
}

// In-order Traversal
void inorderTraversal(struct rbNode *node) {
    if (node) {
        inorderTraversal(node->link[0]);
        printf("%d ", node->data);
        inorderTraversal(node->link[1]);
    }
}

int main() {
    int ch, data;
    while (1) {
        printf("\n1. Insert\n2. Traverse\n3. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertion(data);
                break;
            case 2:
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
