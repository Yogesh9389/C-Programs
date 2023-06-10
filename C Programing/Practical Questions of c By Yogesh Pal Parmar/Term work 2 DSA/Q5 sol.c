#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a key in the binary search tree
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    } else if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function to find the minimum value node in the binary search tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    } else if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found, perform deletion
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* minValue = minValueNode(root->right);
        root->data = minValue->data;
        root->right = deleteNode(root->right, minValue->data);
    }
    return root;
}

// Function to count the total number of leaf nodes in the binary search tree
int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else if (root->left == NULL && root->right == NULL) {
        return 1;
    } else {
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }
}

// Function to count the nodes having both children in the binary search tree
int countNodesWithBothChildren(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;
    } else if (root->left != NULL && root->right != NULL) {
        return 1 + countNodesWithBothChildren(root->left) + countNodesWithBothChildren(root->right);
    } else if (root->left != NULL) {
        return countNodesWithBothChildren(root->left);
    } else {
        return countNodesWithBothChildren(root->right);
    }
}

// Function to count the total number of nodes on the right and left sides of the root node
void countNodesOnSides(struct Node* root, int key, int* leftCount, int* rightCount) {
    if (root == NULL) {
        return;
    } else if (root->data == key) {
        if (root->left != NULL) {
            *leftCount = countLeafNodes(root->left);
        }
        if (root->right != NULL) {
            *rightCount = countLeafNodes(root->right);
        }
        return;
    } else if (key < root->data) {
        countNodesOnSides(root->left, key, leftCount, rightCount);
    } else {
        countNodesOnSides(root->right, key, leftCount, rightCount);
    }
}

// Function to free the memory occupied by the binary search tree
void freeTree(struct Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Function to display the menu options
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Insert a node\n");
    printf("2. Search for a key\n");
    printf("3. Delete a node\n");
    printf("4. Count total number of leaf nodes\n");
    printf("5. Count nodes having both children\n");
    printf("6. Count total number of nodes on left and right sides of the root\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main() {
	printf("Yogesh Pal Parmar MCA 2B 70");
    struct Node* root = NULL;
    int choice, key, leftCount, rightCount;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Node inserted successfully.\n");
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                struct Node* result = search(root, key);
                if (result != NULL) {
                    printf("Key found in the binary search tree.\n");
                } else {
                    printf("Key not found in the binary search tree.\n");
                }
                break;
            case 3:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Node deleted successfully.\n");
                break;
            case 4:
                printf("Total number of leaf nodes: %d\n", countLeafNodes(root));
                break;
            case 5:
                printf("Total number of nodes having both children: %d\n", countNodesWithBothChildren(root));
                break;
            case 6:
                leftCount = 0;
                rightCount = 0;
                countNodesOnSides(root, root->data, &leftCount, &rightCount);
                printf("Total number of nodes on the left side of the root: %d\n", leftCount);
                printf("Total number of nodes on the right side of the root: %d\n", rightCount);
                break;
            case 7:
                freeTree(root);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
