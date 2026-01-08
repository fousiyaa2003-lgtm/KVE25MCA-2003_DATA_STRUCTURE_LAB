#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *end = NULL;
static int size = 0;

// Function to insert at the beginning
void insert_head(int data) {
    struct node *node;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    if (head != NULL) {
        head->prev = node;
        node->next = head;
        head = node;
    } else {
        head = node;
        end = node;
    }
    size++;
}

// Function to insert at the end (This was missing in the photos, so I added it)
void insert_end(int data) {
    struct node *node;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    if (end != NULL) {
        end->next = node;
        node->prev = end;
        end = node;
    } else {
        head = node;
        end = node;
    }
    size++;
}

// Function to insert at a specific position
void insert_pos(int data, int pos) {
    int count = 1;
    struct node *node, *temp;
    temp = head;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;

    do {
        if (count == pos) {
            node->next = temp->next;
            if (temp->next != NULL) { // Check to prevent segfault
                (temp->next)->prev = node;
            }
            node->prev = temp;
            temp->next = node;
            size++;
            break;
        } else {
            count++;
            temp = temp->next;
        }
    } while (count <= pos && temp != NULL);
}

// Function to delete the head node
void delete_head() {
    struct node *temp;
    if (head != NULL) {
        printf("\nNode deleted: %d", head->data);
        temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            end = NULL;
        }
        free(temp);
        size--;
    } else {
        printf("\nLinked list is empty");
    }
}

// Function to delete the end node
void delete_end() {
    if (head == NULL) {
        printf("Linked list is empty!!");
    } else {
        printf("\nNode deleted: %d", end->data);
        struct node *temp = end;
        end = end->prev;
        if (end != NULL) {
            end->next = NULL;
        } else {
            head = NULL;
        }
        free(temp);
        size--;
    }
}

// Function to delete at a specific position
void delete_pos(int pos) {
    int count = 1;
    struct node *temp = head;
    struct node *next_temp;

    // Handle head deletion separately for simplicity or loop
    if (pos == 1) {
        delete_head();
        return;
    }

    do {
        if (count == pos) {
            next_temp = temp->next; // The node to delete
             // Link previous node to next node
            temp->next = next_temp->next;
            
            // Link next node to previous node
            if (next_temp->next != NULL) {
                (next_temp->next)->prev = temp;
            } else {
                end = temp; // If we deleted the last node
            }
            
            printf("\nNode deleted: %d", next_temp->data);
            free(next_temp);
            size--;
            break;
        } else {
            count++;
            temp = temp->next;
        }
    } while (count < pos && temp != NULL);
}

void display_forward() {
    if (head == NULL) {
        printf("\nLinked list is empty!!");
    } else {
        struct node *link = head;
        printf("\n");
        while (link != NULL) {
            printf("%d ", link->data);
            link = link->next;
        }
        printf("\n");
    }
}

void display_reverse() {
    if (end == NULL) {
        printf("\nLinked list is empty!!");
    } else {
        struct node *link = end;
        printf("\n");
        while (link != NULL) {
            printf("%d ", link->data);
            link = link->prev;
        }
        printf("\n");
    }
}

void search() {
    int count = 1;
    if (head == NULL) {
        printf("\nLinked list is empty!!");
    } else {
        int data;
        printf("Enter the number you want to search: ");
        scanf("%d", &data);
        struct node *link = head;
        
        do {
            if (link->data == data) {
                printf("\nThe %d is found in the linked list!! The position is %d", link->data, count);
                return;
            }
            count++;
            link = link->next;
        } while (link != NULL);
        
        printf("\nThe number is not found in the linked list!!");
    }
}

int main() {
    int ch, data, pos;
    do {
        printf("\n1. Insert head\n2. Insert end\n3. Insert at position\n4. Delete head\n5. Delete end\n6. Delete from position\n7. Display forward\n8. Display reverse\n9. Search\n10. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the data you need to store: ");
                scanf("%d", &data);
                insert_head(data);
                break;
            case 2:
                printf("\nEnter the data you need to store: ");
                scanf("%d", &data);
                insert_end(data);
                break;
            case 3:
                printf("\nEnter the data you need to store: ");
                scanf("%d", &data);
                printf("\nEnter the position where you need to store (Head=0 End=%d): ", size);
                scanf("%d", &pos);
                if (pos < 0 || pos > size) {
                    printf("\nInvalid Position!!");
                } else if (pos == 0) {
                    insert_head(data);
                } else if (pos == size) {
                    insert_end(data);
                } else {
                    insert_pos(data, pos);
                }
                break;
            case 4:
                delete_head();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                printf("\nEnter the position where you need to delete from (Head=1 End=%d): ", size);
                scanf("%d", &pos);
                if (pos < 1 || pos > size) {
                    printf("\nInvalid position");
                } else if (pos == 1) {
                    delete_head();
                } else if (pos == size) {
                    delete_end();
                } else {
                    delete_pos(pos);
                }
                break;
            case 7:
                display_forward();
                break;
            case 8:
                display_reverse();
                break;
            case 9:
                search();
                break;
            case 10:
                printf("\nThe program is exiting successfully!");
                break;
            default:
                printf("\nWrong input");
        }
    } while (ch != 10);

    return 0;
}

