#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node* head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    Node* current = head;
    while (current->next != NULL)
        current = current->next;

    current->next = newNode;

    return head;
}

void insertNth(Node* head, int value, int position) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = head;
    int count = 1;
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Invalid position.\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;

    printf("Node inserted successfully.\n");
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
	printf("Yogesh Pal Parmar MCA 2B 70\n");
    Node* head = NULL;
    int choice, value, position;

    do {
        printf("1. Insert into List\n");
        printf("2. Insert Node After Nth Position\n");
        printf("3. Display List\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert into the list: ");
                scanf("%d", &value);
                head = insertNode(head, value);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position after which to insert: ");
                scanf("%d", &position);
                insertNth(head, value, position);
                break;
            case 3:
                printf("Linked List: ");
                displayList(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 4);

    freeList(head);

    return 0;
}
