
#include <stdio.h>

#define SIZE 3

// Function to print the board
void print_board(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

// Function to check if a player has won
int check_winner(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||  // Row
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {  // Column
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }

    return 0;  // No winner yet
}

// Function to check if the board is full (draw condition)
int is_board_full(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;  // Board still has empty spaces
            }
        }
    }
    return 1;  // Board is full
}

int main() {
    char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };  // Empty board
    int row, col;
    int move_count = 0;
    char player = 'X';
    int game_over = 0;

    while (!game_over) {
        print_board(board);  // Print the current state of the board

        // Prompt the current player for a move
        printf("Player %c, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);

        // Validate move (check if it's within bounds and the cell is empty)
        if (row < 1 ; row > SIZE col < 1 col > SIZE  board[row - 1][col - 1] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Make the move
        board[row - 1][col - 1] = player;
        move_count++;

        // Check if the current player wins
        if (check_winner(board, player)) {
            print_board(board);
            printf("Player %c wins!\n", player);
            game_over = 1;
        }
        // Check for a draw (board is full and no winner)
        else if (is_board_full(board)) {
            print_board(board);
            printf("It's a draw!\n");
            game_over = 1;
        }

        // Switch players
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
