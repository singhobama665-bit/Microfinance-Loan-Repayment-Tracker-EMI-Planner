#include <stdio.h>
#include <math.h>

int main() {

float P, R, EMI;
int N;

// Input Section
printf("Enter Principal Amount : ");
scanf("%f", &P);

if (P <= 0) {
    printf("Invalid Principal! Must be greater than 0.\n");
    return 0;
}

printf("Enter Monthly Interest Rate (example: 0.01 for 1%%) : ");
scanf("%f", &R);

if (R <= 0) {
    printf("Invalid Rate! Must be positive.\n");
    return 0;
}

printf("Enter Tenure (Months) : ");
scanf("%d", &N);

if (N <= 0) {
    printf("Invalid Tenure! Must be at least 1 month.\n");
    return 0;
}

// EMI Formula
float A = pow(1 + R, N);
EMI = (P * R * A) / (A - 1);

// Output
printf("\n----------------------------------------\n");
printf("   EMI Calculation Result\n");
printf("----------------------------------------\n");
printf("Principal      : %.2f\n", P);
printf("Interest Rate  : %.3f per month\n", R);
printf("Tenure         : %d months\n", N);
printf("Your EMI       : %.2f\n", EMI);
printf("----------------------------------------\n");

return 0;

}
