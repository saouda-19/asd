#include <stdio.h>
#include <math.h>

// Function to check the convergence of the series 1/n^p
void check_p_series_convergence(double p) {
    if (p > 1) {
        printf("The series 1/n^p converges for p > 1.\n");
    } else {
        printf("The series 1/n^p diverges for p <= 1.\n");
    }
}

// Function to check the convergence of the series 1/n!
void check_factorial_series_convergence() {
    printf("The series 1/n! converges because the factorial grows rapidly.\n");
}

int main() {
    double p;

    // Problem 16: Check the convergence of the series 1/n^p
    printf("Enter the value of p for the series 1/n^p: ");
    scanf("%lf", &p);
    check_p_series_convergence(p);

    // Problem 17: Check the convergence of the series 1/n!
    check_factorial_series_convergence();

    return 0;
}
