#include <stdio.h>

#define MAX_SIZE 10

int L[MAX_SIZE] = {1, 2, 3, 4, 5};
int size = 5;

void insert_end(int L[], int *size, int x) {
    if (*size < MAX_SIZE) {
        L[*size] = x;
        (*size)++;
    } else {
        printf("List is full!\n");
    }
}

int main() {
    insert_end(L, &size,60);  // Insert 60 at the end
    for (int i = 0; i < size; i++) {
        printf("%d ", L[i]);
    }
    return 0;
}
