#include <stdio.h>
#include <stdlib.h>

struct Loan {
float outstanding;
int overdue;
};

int main() {
int n;

printf("Enter number of borrowers : ");
scanf("%d", &n);

// Allocate memory dynamically
struct Loan *book = (struct Loan *)malloc(n * sizeof(struct Loan));

if (book == NULL) {
    printf("Memory not allocated!\n");
    return 0;
}

// Input Borrowers
for (int i = 0; i < n; i++) {
    printf("\nBorrower %d Outstanding : ", i + 1);
    scanf("%f", &book[i].outstanding);

    printf("Is Borrower %d Overdue? (1 = Yes, 0 = No): ", i + 1);
    scanf("%d", &book[i].overdue);
}

// Ask user to add more borrowers
int add;
printf("\nHow many new borrowers to add? : ");
scanf("%d", &add);

if (add > 0) {
    // Resize memory
    book = realloc(book, (n + add) * sizeof(struct Loan));

    if (book == NULL) {
        printf("Memory reallocation failed!\n");
        return 0;
    }

    // Input new borrowers
    for (int i = n; i < n + add; i++) {
        printf("\nNew Borrower %d Outstanding : ", i + 1);
        scanf("%f", &book[i].outstanding);

        printf("Is Borrower %d Overdue? (1 = Yes, 0 = No): ", i + 1);
        scanf("%d", &book[i].overdue);
    }

    n = n + add; // update total borrowers
}

// Display updated loan book
printf("\n------ UPDATED LOAN BOOK ------\n");
for (int i = 0; i < n; i++) {
    printf("Borrower %d: Outstanding = %.2f, Overdue = %d\n",
           i + 1, book[i].outstanding, book[i].overdue);
}

free(book);
return 0;

}
