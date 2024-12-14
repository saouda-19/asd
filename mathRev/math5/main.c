#include <stdio.h>
#include <math.h>

// Function to compute S(n) = sum(i^2) for i = 1 to n
int sum_of_squares(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

// Function to compute S(n) = sum(i^3) for i = 1 to n
int sum_of_cubes(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i * i;
    }
    return sum;
}

// Function to compute S(n) = sum(2^i) for i = 1 to n
int sum_of_powers_of_2(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (int)pow(2, i); // Using pow to compute 2^i
    }
    return sum;
}

// Function to compute S(n) = sum(1/i) for i = 1 to n
double sum_of_reciprocals(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i; // Adding reciprocal of i
    }
    return sum;
}

int main() {
    int n;

    // Input number of terms n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Compute and display S(n) = sum(i^2)
    int sum_sq = sum_of_squares(n);
    printf("S(n) = sum(i^2) for i=1 to n is: %d\n", sum_sq);

    // Compute and display S(n) = sum(i^3)
    int sum_cb = sum_of_cubes(n);
    printf("S(n) = sum(i^3) for i=1 to n is: %d\n", sum_cb);

    // Compute and display S(n) = sum(2^i)
    int sum_pow2 = sum_of_powers_of_2(n);
    printf("S(n) = sum(2^i) for i=1 to n is: %d\n", sum_pow2);

    // Compute and display S(n) = sum(1/i)
    double sum_rec = sum_of_reciprocals(n);
    printf("S(n) = sum(1/i) for i=1 to n is: %.10lf\n", sum_rec);

    return 0;
}
