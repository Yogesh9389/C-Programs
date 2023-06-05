#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Function to search for an element in the BST
struct Node* searchNode(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return searchNode(root->left, value);
    }
    return searchNode(root->right, value);
}

// Function to find the minimum value in a BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform inorder traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to perform preorder traversal of the BST
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to perform postorder traversal of the BST
void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Function to count number of nodes of the BST
void countNode(struct Node* root, int *c) {
    if (root == NULL) {
        return;
    }
    countNode(root->left, c);
    *c = *c + 1;
    countNode(root->right, c);
}

// Function to count number of leaf nodes of the BST
void countLeafNode(struct Node* root, int *c)
{
	if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        *c = *c + 1;
    }   
    countNode(root->left, c);
    countNode(root->right, c);
}

// Function to count number of nodes having two child in the BST
void countNodeTwoChild(struct Node* root, int *c)
{
	if (root == NULL) {
        return;
    }
    if (root->left != NULL && root->right != NULL) {
        *c = *c + 1;
    }   
    countNode(root->left, c);
    countNode(root->right, c);
}

// Function to count number of nodes having only one child in the BST
void countNodeOneChild(struct Node* root, int *c)
{
	if (root == NULL) {
        return;
    }
    if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)){
        *c = *c + 1;
    }   
    countNode(root->left, c);
    countNode(root->right, c);
}

// Function to count number of nodes having even data in the BST
void countEvenInfo(struct Node* root, int *c)
{
	if (root == NULL) {
        return;
    }
    if (root->data % 2 == 0){
    	*c = *c + 1;
    }   
    countNode(root->left, c);
    countNode(root->right, c);
}

int main() {
	printf("Yogesh Pal Parmar MCA 2B 70\n");
    struct Node* root = NULL;
    int choice, value, count;
    while (1) {
        printf("BST Menu:\n");
        printf("1. Insert Element\n");
        printf("2. Search Element\n");
        printf("3. Delete Element\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Count number of nodes\n");
        printf("8. Count number of Leaf nodes\n");
        printf("9. Count number of nodes having only two child\n");
        printf("10.Count number of nodes having only one child\n");
        printf("11.Count number of nodes having even number stored\n");
        printf("12.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("Enter element to search: ");
                scanf("%d", &value);
                if (searchNode(root, value) != NULL) {
                    printf("Element found!\n");
                } else {
                    printf("Element not found!\n");
                }
            	break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
            	break;
            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
            	break;
            case 5:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
            	break;
            case 6:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
            	break;
            case 7:
            	printf("Number of nodes are: ");
            	count = 0;
            	countNode(root, &count);
            	printf("%d", count);
            	printf("\n");
            	break;
            case 8:
            	printf("Number of Leaf nodes are: ");
            	count = 0;
            	countLeafNode(root, &count);
            	printf("%d", count);
            	printf("\n");
            	break;
            case 9:
            	printf("Number of nodes having two child are: ");
            	count = 0;
            	countNodeTwoChild(root, &count);
            	printf("%d", count);
            	printf("\n");
            	break;
            case 10:
            	printf("Number of nodes having only one child are: ");
            	count = 0;
            	countNodeOneChild(root, &count);
            	printf("%d", count);
            	printf("\n");
            	break;
            case 11:
            	printf("Number of nodes with even number stored are: ");
            	count = 0;
            	countEvenInfo(root, &count);
            	printf("%d", count);
            	printf("\n");
            	break;
            case 12:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
