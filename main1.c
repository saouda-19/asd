#include <stdio.h>

#define MAX_SIZE 11  // Maximum size of the list

int L[MAX_SIZE] = {10, 20, 30, 40, 50,60};  // Initialize list with 5 elements

int main() {
    // Print the initialized list
    for(int i = 0; i < 6; i++) {
        printf("%d ", L[i]);
    }
    return 0;
}

