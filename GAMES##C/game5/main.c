#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10  // Size of the number list

// Function to generate a random list of numbers
void generate_random_numbers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;  // Generate numbers between 1 and 100
    }
}

// Function to print the array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to compare the user's sorted list with the correct sorted list
void compare_lists(int correct[], int user[], int size) {
    int correct_count = 0;
    int incorrect_count = 0;

    for (int i = 0; i < size; i++) {
        if (correct[i] == user[i]) {
            correct_count++;
        } else {
            incorrect_count++;
        }
    }

    printf("\nCorrectly placed: %d\n", correct_count);
    printf("Incorrectly placed: %d\n", incorrect_count);
}

int main() {
    srand(time(0));  // Seed the random number generator

    int numbers[SIZE];
    int sorted_numbers[SIZE];
    int user_sorted[SIZE];

    // Generate random numbers
    generate_random_numbers(numbers, SIZE);

    // Copy the random numbers to sorted_numbers for later comparison
    for (int i = 0; i < SIZE; i++) {
        sorted_numbers[i] = numbers[i];
    }

    // Print the unsorted list
    printf("Unsorted list:\n");
    print_array(numbers, SIZE);

    // Sort the numbers for comparison
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (sorted_numbers[i] > sorted_numbers[j]) {
                int temp = sorted_numbers[i];
                sorted_numbers[i] = sorted_numbers[j];
                sorted_numbers[j] = temp;
            }
        }
    }

    // Prompt the user to enter their sorted list
    printf("\nPlease enter the numbers in ascending order:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &user_sorted[i]);
    }

    // Compare the user's sorted list with the correct sorted list
    compare_lists(sorted_numbers, user_sorted, SIZE);

    return 0;
}
