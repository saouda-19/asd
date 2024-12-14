#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to determine the winner
const char* get_winner(const char* user_choice, const char* computer_choice) {
    if (strcmp(user_choice, computer_choice) == 0) {
        return "It's a tie!";
    }
    if ((strcmp(user_choice, "rock") == 0 && strcmp(computer_choice, "scissors") == 0) ||
        (strcmp(user_choice, "paper") == 0 && strcmp(computer_choice, "rock") == 0) ||
        (strcmp(user_choice, "scissors") == 0 && strcmp(computer_choice, "paper") == 0)) {
        return "You win!";
    } else {
        return "Computer wins!";
    }
}

int main() {
    // Seed random number generator
    srand(time(0));

    // Game variables
    char user_choice[10];
    char* choices[] = {"rock", "paper", "scissors"};
    char computer_choice[10];
    char play_again;

    do {
        // Ask for user input
        printf("Enter 'rock', 'paper', or 'scissors': ");
        scanf("%s", user_choice);

        // Check for valid input
        if (strcmp(user_choice, "rock") != 0 && strcmp(user_choice, "paper") != 0 && strcmp(user_choice, "scissors") != 0) {
            printf("Invalid choice. Please enter 'rock', 'paper', or 'scissors'.\n");
            continue;
        }

        // Generate computer's choice randomly
        int random_index = rand() % 3;  // Random number between 0 and 2
        strcpy(computer_choice, choices[random_index]);

        // Display choices
        printf("You chose: %s\n", user_choice);
        printf("Computer chose: %s\n", computer_choice);

        // Determine the winner
        printf("%s\n", get_winner(user_choice, computer_choice));

        // Ask if the user wants to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);  // The space before %c handles any leftover newline characters
    } while (play_again == 'y' || play_again == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}
