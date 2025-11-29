#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Loan {
char name[50];
float principal;
float rate;
int months;
float emi;
float outstanding;
int overdue;
};

float calculateEMI(float P, float R, int N) {
return (P * R * pow(1 + R, N)) / (pow(1 + R, N) - 1);
}

void addBorrower(struct Loan *b, int index) {
printf("\nEnter Borrower Name : ");
scanf("%s", b[index].name);

printf("Enter Principal Amount : ");
scanf("%f", &b[index].principal);

printf("Enter Monthly Interest Rate (0.01 for 1%%) : ");
scanf("%f", &b[index].rate);

printf("Enter Tenure (months) : ");
scanf("%d", &b[index].months);

b[index].emi = calculateEMI(b[index].principal, b[index].rate, b[index].months);
b[index].outstanding = b[index].principal;
b[index].overdue = 0;

printf("Borrower Added! EMI = %.2f\n", b[index].emi);


}

void viewAll(struct Loan *b, int n) {
printf("\n---- LOAN BOOK ----\n");
for (int i = 0; i < n; i++) {
printf("%d. %s | EMI: %.2f | Outstanding: %.2f | Overdue: %d\n",
i + 1, b[i].name, b[i].emi, b[i].outstanding, b[i].overdue);
}
}

void makePayment(struct Loan *b, int index) {
float pay;
printf("Enter Amount Paid : ");
scanf("%f", &pay);

if (pay >= b[index].emi) {
    printf("Full EMI Paid (or Extra).\n");
    b[index].outstanding -= pay;
} else {
    printf("Partial Payment.\n");
    b[index].outstanding -= pay;
    b[index].overdue = 1;
}

if (b[index].outstanding < 0)
    b[index].outstanding = 0;

printf("Updated Outstanding = %.2f\n", b[index].outstanding);

}

void saveToFile(struct Loan *b, int n) {
FILE *fp = fopen("loanbook.txt", "w");

for (int i = 0; i < n; i++) {
    fprintf(fp, "%s %.2f %.2f %d %.2f %.2f %d\n",
            b[i].name, b[i].principal, b[i].rate, b[i].months,
            b[i].emi, b[i].outstanding, b[i].overdue);
}

fclose(fp);
printf("Data Saved to File.\n");

}

int main() {
int n = 0, choice;
struct Loan *book = malloc(100 * sizeof(struct Loan)); // max 100 borrowers

while (1) {
    printf("\n------ MICROFINANCE SYSTEM ------\n");
    printf("1. Add Borrower\n");
    printf("2. View All Borrowers\n");
    printf("3. Make EMI Payment\n");
    printf("4. Save Loan Book to File\n");
    printf("5. Exit\n");
    printf("Enter choice : ");
    scanf("%d", &choice);

    if (choice == 1) {
        addBorrower(book, n);
        n++;
    }
    else if (choice == 2) {
        viewAll(book, n);
    }
    else if (choice == 3) {
        int id;
        printf("Enter Borrower Number : ");
        scanf("%d", &id);
        if (id >= 1 && id <= n)
            makePayment(book, id - 1);
        else
            printf("Invalid Borrower!\n");
    }
    else if (choice == 4) {
        saveToFile(book, n);
    }
    else if (choice == 5) {
        printf("Exiting...\n");
        break;
    }
    else {
        printf("Invalid Option!\n");
    }
}

free(book);
return 0;

}