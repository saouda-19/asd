#include <stdio.h>

#define MAX_SIZE 10

int L[MAX_SIZE] = {10, 20, 30, 20, 50};
int size = 5;

int count(int L[], int size, int x) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (L[i] == x) {
            count++;
        }
    }
    return count;
}

int main() {
    int result = count(L, size, 20);
    printf("20 appears %d times\n", result);
    return 0;
}