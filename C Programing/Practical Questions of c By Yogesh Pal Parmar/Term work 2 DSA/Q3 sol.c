#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int data) {
    if (*head == NULL) {
        *head = createNode(data);
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = createNode(data);
}

// Function to remove duplicate nodes from an unsorted linked list
void removeDuplicates(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    // Hash table to keep track of seen elements
    int hash[1000] = {0};
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL) {
        // Check if current data is already seen
        if (hash[current->data] == 1) {
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            hash[current->data] = 1;
            prev = current;
            current = current->next;
        }
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
	printf("Yogesh Pal Parmar MCA 2B 70");
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("1. Insert a node\n");
        printf("2. Remove duplicate nodes\n");
        printf("3. Print the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertNode(&head, data);
                break;
            case 2:
                removeDuplicates(&head);
                printf("Duplicate nodes removed.\n");
                break;
            case 3:
                printf("Linked List: ");
                printList(head);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}
