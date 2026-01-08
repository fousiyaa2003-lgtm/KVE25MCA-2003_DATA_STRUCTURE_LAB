#include <stdio.h>
#include <stdlib.h> // Fixed typo: was stdlib.b in notes

struct node {
    int info;
    struct node *link;
};

struct node *start = NULL;

// Function Prototypes
void createList();
void display();
void insertAtFront();
void insertAtEnd();
void insertAtPosition();
void deleteFirst();
void deleteEnd();
void deletePosition();

int main() {
    int choice;
    while(1) {
        printf("\n1. Display list\n");
        printf("2. Insertion at the beginning\n");
        printf("3. Insertion at the end\n");
        printf("4. Insertion at any position\n");
        printf("5. Deletion at the beginning\n");
        printf("6. Deletion at the end\n");
        printf("7. Deletion at any position\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: display(); break;
            case 2: insertAtFront(); break;
            case 3: insertAtEnd(); break;
            case 4: insertAtPosition(); break;
            case 5: deleteFirst(); break;
            case 6: deleteEnd(); break;
            case 7: deletePosition(); break;
            case 8: exit(0); break;
            default: printf("\nIncorrect choice\n");
        }
    }
    return 0;
}

void createList() {
    int n, data, i;
    struct node *newnode, *temp;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    if (n != 0) {
        printf("\nEnter the number to be inserted: ");
        scanf("%d", &data);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->info = data;
        newnode->link = NULL;
        start = newnode;
        temp = start;

        for (i = 2; i <= n; i++) {
            newnode = (struct node*)malloc(sizeof(struct node));
            printf("\nEnter the number to be inserted: ");
            scanf("%d", &data);
            newnode->info = data;
            newnode->link = NULL;
            temp->link = newnode;
            temp = temp->link;
        }
        printf("\nThe list is created\n");
    } else {
        printf("\nThe list is already created\n");
    }
}

void display() {
    struct node *temp;
    if (start == NULL) {
        printf("\nList is empty\n");
    } else {
        temp = start;
        while (temp != NULL) {
            printf("Data = %d\n", temp->info);
            temp = temp->link;
        }
    }
}

void insertAtFront() {
    int data;
    struct node *temp; // In notes, this acts as newnode
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->link = start;
    start = temp;
}

void insertAtEnd() {
    int data;
    struct node *temp, *head; 
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the number to be inserted: ");
    scanf("%d", &data);
    
    temp->link = NULL; // Logic correction: End node link must be NULL
    temp->info = data;
    
    head = start;
    if(head == NULL) {
        start = temp;
    } else {
        while (head->link != NULL) {
            head = head->link;
        }
        head->link = temp;
    }
}

void insertAtPosition() {
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter position and data: ");
    scanf("%d %d", &pos, &data);
    
    temp = start;
    newnode->info = data;
    newnode->link = NULL;

    // Logic to traverse to pos-1
    while (i < pos - 1 && temp != NULL) {
        temp = temp->link;
        i++;
    }
    
    if(temp != NULL) {
        newnode->link = temp->link;
        temp->link = newnode;
    } else {
        printf("\nPosition out of range\n");
    }
}

void deleteFirst() {
    struct node *temp;
    if (start == NULL) {
        printf("\nList is empty\n");
    } else {
        temp = start;
        start = start->link;
        printf("\nThe popped element is: %d\n", temp->info); // Added formatting
        free(temp);
    }
}

void deleteEnd() {
    struct node *temp, *prevnode;
    if (start == NULL) {
        printf("\nList is empty\n");
    } else {
        temp = start;
        while (temp->link != NULL) {
            prevnode = temp;
            temp = temp->link;
        }
        prevnode->link = NULL;
        printf("The popped element is: %d", temp->info);
        free(temp);
    }
}

void deletePosition() {
    int i = 1, pos;
    struct node *temp, *position;
    
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    printf("\nEnter the position to be deleted: ");
    scanf("%d", &pos);

    // NOTE: In the notes, there was a malloc here. That is incorrect for deletion.
    // We do not allocate memory for a node we are about to delete.
    // Removed: position = malloc(...) 

    temp = start;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->link;
        i++;
    }

    if(temp != NULL && temp->link != NULL) {
        position = temp->link; // Target node
        temp->link = position->link; // Link previous to next
        printf("The popped element is: %d at [%d]", position->info, pos);
        free(position);
    } else {
        printf("\nInvalid position\n");
    }
}
