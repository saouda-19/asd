#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ATTEMPTS 6
#define WORD_LIST_SIZE 5

// Function to choose a random word from the predefined list
const char* get_random_word() {
    const char* words[WORD_LIST_SIZE] = {
        "programming", "hangman", "computer", "developer", "algorithm"
    };
    srand(time(0));  // Seed the random number generator
    return words[rand() % WORD_LIST_SIZE];
}

// Function to display the current state of the guessed word
void display_word(const char* word, char* guessed_word) {
    for (int i = 0; i < strlen(word); i++) {
        if (guessed_word[i] == '_') {
            printf("_ ");
        } else {
            printf("%c ", guessed_word[i]);
        }
    }
    printf("\n");
}

// Function to check if the player has guessed the word correctly
int check_win(const char* word, char* guessed_word) {
    return strcmp(word, guessed_word) == 0;
}

// Function to update the guessed word if the letter is correct
int update_guessed_word(const char* word, char* guessed_word, char guess) {
    int correct = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == guess && guessed_word[i] == '_') {
            guessed_word[i] = guess;
            correct = 1;
        }
    }
    return correct;
}

int main() {
    // Choose a random word from the list
    const char* word = get_random_word();
    int word_length = strlen(word);

    // Create a guessed_word array initialized with underscores
    char guessed_word[word_length + 1];  // +1 for the null terminator
    for (int i = 0; i < word_length; i++) {
        guessed_word[i] = '_';
    }
    guessed_word[word_length] = '\0';  // Null terminate the string

    int attempts_left = MAX_ATTEMPTS;
    char guessed_letter;
    int game_over = 0;

    printf("Welcome to Hangman!\n");

    // Game loop
    while (attempts_left > 0 && !game_over) {
        printf("\nWord: ");
        display_word(word, guessed_word);  // Display the current state of the guessed word
        printf("Attempts remaining: %d\n", attempts_left);
        printf("Guess a letter: ");

        // Read the guessed letter
        scanf(" %c", &guessed_letter);  // The space before %c skips any leading whitespace

        // Check if the guessed letter is valid (single alphabetic character)
        if ((guessed_letter < 'a'  guessed_letter > 'z') && (guessed_letter < 'A'  guessed_letter > 'Z')) {
            printf("Invalid input. Please enter a letter.\n");
            continue;
        }

        // Convert to lowercase if the input is uppercase
        if (guessed_letter >= 'A' && guessed_letter <= 'Z') {
            guessed_letter = guessed_letter + ('a' - 'A');
        }

        // Check if the guessed letter is correct
        if (update_guessed_word(word, guessed_word, guessed_letter)) {
            printf("Good guess!\n");
        } else {
            attempts_left--;
            printf("Incorrect guess.\n");
        }

        // Check if the player has won
        if (check_win(word, guessed_word)) {
            game_over = 1;
            printf("\nCongratulations! You've guessed the word: %s\n", word);
        }
    }

    // If the game ends and the player still hasn't guessed the word
    if (!game_over) {
        printf("\nGame Over! You've run out of attempts. The word was: %s\n", word);
    }

    return 0;
}
