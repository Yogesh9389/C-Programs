#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to swap two characters
void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to perform Quick sort on the array
void quickSort(char arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to display the array of characters
void displayArray(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

int main() {
	printf("Yogesh Pal Parmar MCA 2B 70\n");
    char arr[100];
    int size = 0;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enter a sequence of characters\n");
        printf("2. Sort the sequence using Quick sort\n");
        printf("3. Print the sorted array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the sequence of characters: ");
                scanf("%s", arr);
                size = strlen(arr);
                printf("Sequence of characters entered: %s\n", arr);
                break;
            case 2:
                if (size > 0) {
                    quickSort(arr, 0, size - 1);
                    printf("Sequence of characters sorted using Quick sort.\n");
                } else {
                    printf("Sequence of characters is empty. Please enter a sequence.\n");
                }
                break;
            case 3:
                if (size > 0) {
                    printf("Sorted array: ");
                    displayArray(arr, size);
                } else {
                    printf("Sequence of characters is empty. Please enter a sequence.\n");
                }
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
