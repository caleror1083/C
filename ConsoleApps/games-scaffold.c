// Arup Guha
// 10/19/2011
// Scaffold for COP 3223 Program #4.

#include <stdio.h>
#include <time.h>
#include <math.h>

const int GUESSING_GAME = 1;
const int SQUARE_GAME = 2;
const int SEE_SCORE = 3;
const int QUIT = 4;

const int SIZE = 3;
const int MAX_SQUARE_VALUE = 20;
const int DEFAULT_MAX_GUESS = 100;
const int MAX_RAND_VALUE = 32767;
const int INVALID = -1;

int menu();

int getGuessScore(int max, int numguesses);
int guessGame(int max);

int winningSquare(int square[][SIZE]);
void fillSquare(int square[][SIZE]);
void printSquare(int square[][SIZE]);
int checkRows(int square[][SIZE]);
int checkCols(int square[][SIZE]);
int getSum(int square[][SIZE]);
int validRowCol(int row, int col);

int getSquareScore(int square[][SIZE], int first_sum, int num_turns);
int playSquareGame();

int main(void) {

    srand(time(0));

    int total = 0, choice;

    choice = menu();

    // Loop until the user quits.
    while (choice != QUIT) {

        // Execute the guessing game.
        if (choice == GUESSING_GAME) {

            int max;
            printf("What do you want the maximum value in the guessing game to be?\n");
            scanf("%d", &max);

            // If the user chooses an invalid max, reset the game to 100.
            if (max < 2 || max > MAX_RAND_VALUE) {
                printf("Sorry, you chose an invalid maximum, you'll play with a maximum of 100.\n");
                max = DEFAULT_MAX_GUESS;
            }

            total += guessGame(max);
        }

        // Play the square game.
        else if (choice == SQUARE_GAME) {
            total += playSquareGame();
        }

        // Just print out the user's score.
        else if (choice == SEE_SCORE) {
            printf("Your current score is %d.\n", total);
        }

        // Get the user's next choice.
        choice = menu();
    }

    // Print out the final score.
    printf("Your final score is %d.\n", total);
    return 0;
}


// Precondition(s): None
// Postcondition(s): Prompts the user with the menu and continues to read in their choice until they
//                enter a valid choice in between 1 and 4, which then gets returned.
int menu() {

}

// Precondition(s): 1 < max < 32767
// Postcondition(s): Generates a random number in the range 1 to max, inclusive, and allows the
//                user to guess the number. After each guess, the user is told to guess lower or
//                higher, until they guess the correct number. At this point, their score is
//                returned, which is based upon the number of guesses it took them to guess the
//                secret number.
int guessGame(int max) {


}

// Precondition(s): 1 < max < 32767, represents the maximum possible number in the guessing game, and
//               numguesses represents the number of guesses needed for a guessing game with the
//               range of choices from 1 to max, inclusive.
// Postcondition(s): Returns the score for the instance of the guessing game described.
int getGuessScore(int max, int num_guesses) {

    // Best we can guarantee in a game, using binary search.
    int best = (int)ceil(log(max+1)/log(2));

    // The score is better, the fewer guesses you make.
    int score = 2*best - num_guesses;

    // This is so we can avoid giving out negative scores.
    if (score < 0)
        score = 0;

    return score;
}

// Precondition(s): square has dimensions SIZE x SIZE
// Postcondition(s): square is randomly filled with numbers in between 1 and MAX.
void fillSquare(int square[][SIZE]) {

}

// Precondition(s): square has dimensions SIZE x SIZE
// Postcondition(s): prints out the square in SIZE rows,
//                 in a format with 4 spaces per entry, right justified.
void printSquare(int square[][SIZE]) {

}

// Precondition(s): square has dimensions SIZE x SIZE
// Postconditions(s): If all SIZE rows add up to the same value, this value is returned.
//                    Otherwise, -1 is returned to indicate at least 2 different row sums.
int checkRows(int square[][SIZE]) {

}

// Precondition(s): square has dimensions SIZE x SIZE.
// Postconditions(s): Returns 1 if all the rows and columns of square add to the same value.
//                    Returns 0 otherwise.
int winningSquare(int square[][SIZE]) {

}

// Precondition(s): square has dimensions SIZE x SIZE.
// Postconditions(s): If all SIZE columns add up to the same value, this value is returned.
//                    Otherwise, -1 is returned to indicate at least 2 different column sums.
int checkCols(int square[][SIZE]) {

}

// Precondition(s): square has dimensions SIZE x SIZE.
// Postconditions(s): Returns the sum of all the integers stored in square.
int getSum(int square[][SIZE]) {

}

// Precondition(s): None
// Postcondition(s): Executes the square game and returns the user's score.
int playSquareGame() {

}

// Precondition(s): none
// Postcondition(s): Returns 1 if 0 <= row < SIZE and 0 <= col < SIZE. Returns 0 otherwise.
int validRowCol(int row, int col) {

}

// Precondition(s): square is the end result of the square game, first_sum is the
//                  original sum of the values in the square at the starting of that
//                  instance of the square game and num_turns is the number of turns
//                  taken in that instance of the square game.
// Postcondition(s): The score of the given instance of the square game is returned.
int getSquareScore(int square[][SIZE], int first_sum, int num_turns) {

    // Calculate the difference in sum between the original and winning square.
    int new_sum = getSum(square);
    int diff = abs(new_sum - first_sum);

    // Calculate the number of squares that didn't have to be changed, assuming that each
    // square was changed only once.
    int turn_diff = SIZE*SIZE - num_turns;

    // Don't let this fall below 0.
    if (turn_diff < 0)
        turn_diff = 0;

    // This is the turn difference plus a weighted value that ranges from 0 to SIZE x SIZE.
    // The weighting is based on what percentage the difference of the sum of the square is
    // from the original sum of the square. The lower the percentage, the closer your score
    // is to SIZE x SIZE.
    return turn_diff + SIZE*SIZE*(first_sum - diff)/first_sum;
}
