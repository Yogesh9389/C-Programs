#include <stdio.h>
#include <stdlib.h>

struct Process {
    int processID;
    int executionTime;
    struct Process* next;
};

// Function to create a new process
struct Process* createProcess(int processID, int executionTime) {
    struct Process* newProcess = (struct Process*)malloc(sizeof(struct Process));
    newProcess->processID = processID;
    newProcess->executionTime = executionTime;
    newProcess->next = NULL;
    return newProcess;
}

// Function to insert a process at the end of the circular linked list
void insertProcess(struct Process** head, struct Process** tail, int processID, int executionTime) {
    struct Process* newProcess = createProcess(processID, executionTime);
    if (*head == NULL) {
        *head = newProcess;
        *tail = newProcess;
        (*tail)->next = *head;
    } else {
        (*tail)->next = newProcess;
        *tail = newProcess;
        (*tail)->next = *head;
    }
}

// Function to allocate time slots to processes and print the completion time for each process
void allocateTimeSlots(struct Process* head, int timeSlot) {
    if (head == NULL) {
        printf("No processes available.\n");
        return;
    }

    struct Process* current = head;
    int totalTime = 0;

    printf("Allocation of time slots:\n");

    do {
        if (current->executionTime <= timeSlot) {
            printf("Process %d completed in %d ms.\n", current->processID, current->executionTime);
            totalTime += current->executionTime;
            struct Process* temp = current;
            current = current->next;
            free(temp);
        } else {
            printf("Process %d completed in %d ms.\n", current->processID, timeSlot);
            current->executionTime -= timeSlot;
            totalTime += timeSlot;
            current = current->next;
        }
    } while (current != head);

    printf("\nTotal execution time: %d ms\n", totalTime);
}

// Function to display the menu options
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add a process\n");
    printf("2. Allocate time slots and print completion time\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
	printf("Yogesh Pal Parmar MCA 2B 70\n");
    struct Process* head = NULL;
    struct Process* tail = NULL;
    int choice, processID, executionTime;
    int timeSlot = 10;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the process ID: ");
                scanf("%d", &processID);
                printf("Enter the execution time: ");
                scanf("%d", &executionTime);
                insertProcess(&head, &tail, processID, executionTime);
                printf("Process added.\n");
                break;
            case 2:
                allocateTimeSlots(head, timeSlot);
                head = NULL;
                tail = NULL;
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
