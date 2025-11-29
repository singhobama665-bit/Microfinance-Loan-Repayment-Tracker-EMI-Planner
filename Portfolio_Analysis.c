#include <stdio.h>

// Function to take borrower data

void takeInput(float outstanding[], int overdue[], int n) {
for (int i = 0; i < n; i++) {
printf("\nBorrower %d Outstanding : ", i + 1);
scanf("%f", &outstanding[i]);

//outstanding --> The remaining loan amount that the borrower still has to pay.

    printf("Is Borrower %d Overdue? (1=Yes, 0=No): ", i + 1);
    scanf("%d", &overdue[i]);
}


}

// Function to calculate total outstanding and delinquency rate
void calculateTotals(float outstanding[], int overdue[], int n,
float *total_outstanding, float *del_rate) {

*total_outstanding = 0;
int delinquent = 0;

for (int i = 0; i < n; i++) {
    *total_outstanding += outstanding[i];
    if (overdue[i] == 1)
        delinquent++;
}

*del_rate = (delinquent / (float)n) * 100;


}

// Function to display report
void showPortfolioReport(float total, float rate) {
printf("\n-----------------------------\n");
printf("     PORTFOLIO REPORT\n");
printf("-----------------------------\n");
printf("Total Outstanding : %.2f\n", total);
printf("Delinquency Rate  : %.2f%%\n", rate);
printf("-----------------------------\n");
}

int main() {

int n;
printf("Enter number of borrowers : ");
scanf("%d", &n);

float outstanding[n];
int overdue[n];

takeInput(outstanding, overdue, n);

float total_outstanding, delinquency_rate;

calculateTotals(outstanding, overdue, n,
                &total_outstanding, &delinquency_rate);

showPortfolioReport(total_outstanding, delinquency_rate);

return 0;

}
