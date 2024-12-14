#include <stdio.h>

#define MAX_SIZE 10

int L[MAX_SIZE] = {10, 20, 30, 40, 50};
int size = 5;

int search(int L[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (L[i] == x) {
            return i;  // Return the index of the first occurrence
        }
    }
    return -1;  // Element not found
}

int main() {
    int index = search(L, size, 40);
    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }
    return 0;
}