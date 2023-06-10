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

    if (value < head->data) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data < value)
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

Node* mergeLists(Node* list1, Node* list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    Node* mergedList = NULL;
    if (list1->data < list2->data) {
        mergedList = list1;
        mergedList->next = mergeLists(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = mergeLists(list1, list2->next);
    }

    return mergedList;
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
    Node* list1 = NULL;
    Node* list2 = NULL;
    Node* mergedList = NULL;
    int choice, value;

    do {
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Merge Lists\n");
        printf("4. Display Merged List\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert into List 1: ");
                scanf("%d", &value);
                list1 = insertNode(list1, value);
                break;
            case 2:
                printf("Enter the value to insert into List 2: ");
                scanf("%d", &value);
                list2 = insertNode(list2, value);
                break;
            case 3:
                mergedList = mergeLists(list1, list2);
                printf("Lists merged successfully.\n");
                break;
            case 4:
                printf("Merged List: ");
                displayList(mergedList);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 5);

    freeList(list1);
    freeList(list2);
    freeList(mergedList);

    return 0;
}
