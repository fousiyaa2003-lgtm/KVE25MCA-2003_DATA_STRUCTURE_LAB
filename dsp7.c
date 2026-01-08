#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left, *right;
    int data;
};

struct node *root = NULL; // Global root pointer

// Function to create a new node
struct node *newNode(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to insert a node
struct node *insert(struct node *root, int value) {
    if (root == NULL) {
        return newNode(value);
    }
    else if (value == root->data) {
        printf("Same data can't be stored ");
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    else if (value < root->data) {
        root->left = insert(root->left, value);
    }
    return root;
}

// Inorder Traversal: Left -> Root -> Right
void inorderTraversal(struct node *root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Preorder Traversal: Root -> Left -> Right
void preorderTraversal(struct node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder Traversal: Left -> Right -> Root
void postorderTraversal(struct node *root) {
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Function to search for a value
struct node *search(struct node *root, int key) {
    if (root == NULL) {
        printf("\n NOT FOUND! \n");
        return NULL;
    }
    else if (root->data == key) {
        printf("\n FOUND! \n");
        return root;
    }
    else {
        if (root->data < key)
            return search(root->right, key);
        return search(root->left, key);
    }
}

// Helper function to find the node with minimum value (for deletion)
struct node *minValueNode(struct node *node) {
    struct node *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node
struct node *deleteNode(struct node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    int opt, value, searchv, key;
    do {
        printf("\n1) Create Root Node \n2) Insert Node \n3) Search \n4) Inorder Traversal \n5) Preorder Traversal \n6) Postorder Traversal \n7) Delete \n8) Quit \n");
        printf("Choose Option :: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("\nEnter a number: ");
                scanf("%d", &value);
                root = newNode(value);
                break;
            case 2:
                printf("\nEnter a number: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 3:
                printf("\nEnter a number: ");
                scanf("%d", &searchv);
                search(root, searchv);
                break;
            case 4:
                printf("\n.............\n");
                inorderTraversal(root);
                printf("\n.............\n");
                break;
            case 5:
                printf("\n.............\n");
                preorderTraversal(root);
                printf("\n.............\n");
                break;
            case 6:
                printf("\n.............\n");
                postorderTraversal(root);
                printf("\n.............\n");
                break;
            case 7:
                printf("\nEnter a number to be deleted: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 8:
                 printf("Exiting...\n");
                 break;
            default:
                printf("Invalid option!");
        }
    } while (opt != 8);

    return 0;
}
