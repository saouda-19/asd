#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int targetNumber, userGuess, attempts = 0;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random number between 1 and 100
    targetNumber = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100. Try to guess it.\n");

    // Loop until the user guesses the correct number
    do {
        printf("Enter your guess: ");
        scanf("%d", &userGuess);
        attempts++;

        if (userGuess < targetNumber) {
            printf("Too low! Try again.\n");
        } else if (userGuess > targetNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("Correct! The number was %d.\n", targetNumber);
            printf("It took you %d attempts to guess the correct number.\n", attempts);
        }
    } while (userGuess != targetNumber);

    return 0;
}
