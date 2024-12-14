#include <stdio.h>
#include <math.h>

// Function to calculate the sum of the first n terms of a geometric series
// S = a * (1 - r^n) / (1 - r), for r != 1
double geometricSum(double a, double r, int n) {
    if (r == 1) {
        return a * n;  // If r = 1, the series is simply a repeated n times
    }
    return a * (1 - pow(r, n)) / (1 - r);
}

// Function to calculate the sum of an infinite geometric series
// S = a / (1 - r), for |r| < 1
double infiniteGeometricSum(double a, double r) {
    if (fabs(r) >= 1) {
        printf("The series does not converge for r >= 1 or r <= -1.\n");
        return 0; // The series does not converge
    }
    return a / (1 - r);
}

int main() {
    int choice;
    double a, r, sum;
    int n;

    // Ask user for which problem to solve
    printf("Choose a problem to solve:\n");
    printf("1. Sum of a geometric series (finite)\n");
    printf("2. Sum of an infinite geometric series\n");
    printf("Enter 1 or 2: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Problem 11: Sum of finite geometric series
        printf("Enter the first term (a): ");
        scanf("%lf", &a);
        printf("Enter the common ratio (r): ");
        scanf("%lf", &r);
        printf("Enter the number of terms (n): ");
        scanf("%d", &n);

        sum = geometricSum(a, r, n);
        printf("The sum of the first %d terms of the geometric series is: %.5lf\n", n, sum);

    } else if (choice == 2) {
        // Problem 12: Sum of infinite geometric series
        printf("Enter the first term (a): ");
        scanf("%lf", &a);
        printf("Enter the common ratio (r): ");
        scanf("%lf", &r);

        sum = infiniteGeometricSum(a, r);
        if (sum != 0) {
            printf("The sum of the infinite geometric series is: %.5lf\n", sum);
        }

    } else {
        printf("Invalid choice. Please enter either 1 or 2.\n");
    }

    return 0;
}
