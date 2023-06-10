#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of a linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to split the linked list into two lists
void split(struct Node* P, struct Node** Q, struct Node** R) {
    struct Node* currentP = P;
    struct Node* currentQ = NULL;
    struct Node* currentR = NULL;
    int position = 1;

    while (currentP != NULL) {
        if (position % 2 == 1) {
            // Insert the node into Q (odd positions)
            if (*Q == NULL) {
                *Q = currentP;
                currentQ = *Q;
            } else {
                currentQ->next = currentP;
                currentQ = currentQ->next;
            }
        } else {
            // Insert the node into R (even positions)
            if (*R == NULL) {
                *R = currentP;
                currentR = *R;
            } else {
                currentR->next = currentP;
                currentR = currentR->next;
            }
        }

        position++;
        currentP = currentP->next;
    }

    // Set the next pointers of the last nodes in Q and R as NULL
    if (currentQ != NULL)
        currentQ->next = NULL;
    if (currentR != NULL)
        currentR->next = NULL;
}

// Function to print a linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory occupied by the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
	printf("Yogesh Pal Parmar MCA 2B 70\n");
    struct Node* P = NULL;  // Original linked list
    struct Node* Q = NULL;  // Linked list containing odd positions
    struct Node* R = NULL;  // Linked list containing even positions

    int choice, data;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert element into P\n");
        printf("2. Split P into Q and R\n");
        printf("3. Print Q and R\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insert(&P, data);
                break;
            case 2:
                split(P, &Q, &R);
                printf("P has been split into Q and R.\n");
                break;
            case 3:
                printf("Linked list Q: ");
                printList(Q);

                printf("Linked list R: ");
                printList(R);
                break;
            case 4:
                // Free the memory occupied by the linked lists
                freeList(Q);
                freeList(R);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
