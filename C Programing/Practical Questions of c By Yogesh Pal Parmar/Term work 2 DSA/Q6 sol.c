#include <stdio.h>
#include <stdlib.h>

// Structure for a term in the polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term with the given coefficient and exponent
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into the polynomial
void insertTerm(struct Term** poly, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);

    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to add two polynomials and return the result
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0) {
                insertTerm(&result, sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

// Function to display the polynomial
void displayPolynomial(struct Term* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
    } else {
        struct Term* current = poly;
        while (current != NULL) {
            printf("(%dx^%d) ", current->coefficient, current->exponent);
            if (current->next != NULL) {
                printf("+ ");
            }
            current = current->next;
        }
        printf("\n");
    }
}

// Function to free the memory occupied by the polynomial
void freePolynomial(struct Term* poly) {
    struct Term* current = poly;
    struct Term* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Function to display the menu options
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add a term to the first polynomial\n");
    printf("2. Add a term to the second polynomial\n");
    printf("3. Add the polynomials and display the result\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
	printf("Yogesh Pal Parmar MCA 2B 70\n");
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    struct Term* result = NULL;

    int choice, coefficient, exponent;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the coefficient: ");
                scanf("%d", &coefficient);
                printf("Enter the exponent: ");
                scanf("%d", &exponent);
                insertTerm(&poly1, coefficient, exponent);
                printf("Term added to the first polynomial.\n");
                break;
            case 2:
                printf("Enter the coefficient: ");
                scanf("%d", &coefficient);
                printf("Enter the exponent: ");
                scanf("%d", &exponent);
                insertTerm(&poly2, coefficient, exponent);
                printf("Term added to the second polynomial.\n");
                break;
            case 3:
                result = addPolynomials(poly1, poly2);
                printf("Resultant polynomial: ");
                displayPolynomial(result);
                freePolynomial(result);
                break;
            case 4:
                freePolynomial(poly1);
                freePolynomial(poly2);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
