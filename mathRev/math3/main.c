#include <stdio.h>
#include <math.h>

// Function to compute a_n for problem 14
int a_n(int n) {
    return 1;  // Since a_n = 1 for all n
}

// Function to compute b_n for problem 15
int b_n(int n) {
    return pow(2, n - 1);  // b_n = 2^(n-1)
}

int main() {
    int n;

    // Problem 14
    printf("Enter n for sequence a_n: ");
    scanf("%d", &n);
    printf("a_%d = %d\n", n, a_n(n));

    // Problem 15
    printf("Enter n for sequence b_n: ");
    scanf("%d", &n);
    printf("b_%d = %d\n", n, b_n(n));

    return 0;
}
