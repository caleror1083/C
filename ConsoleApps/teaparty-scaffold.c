// Arup Guha
// 4/3/2012
// Scaffold for COP 3223 Program #5: Tea Party

#include <stdio.h>
#include <time.h>

#define SLOW_MODE 1

#define NUMPLAYERS 2
#define NUMPIECES 7
#define MAXLEN 20
#define NO_WINNER -1

const char CHOICES[NUMPIECES+1][MAXLEN] = {"PLATE", "NAPKIN", "TEA CUP", "CREAM AND SUGAR", "SANDWICH", "FRUIT", "DESSERT", "LOSE A PIECE"};

void update_player(int player[], int square);
int get_lost_piece(int player[]);
int search(int piece_list[], int choice);
int get_spin();
void init_player(int player[]);
int get_winner(int players[][NUMPIECES]);
int get_next_player(int player_num);
int count_pieces(int player[]);
void print_player(int player[], int player_num);

int main() {

    srand(time(0));

    int players[NUMPLAYERS][NUMPIECES];

    // Initialize each player in the game.
    int i;
    for (i=0; i<NUMPLAYERS; i++)
        init_player(players[i]);

    int player_number = 0;

    // Play until we get a winner.
    int status = get_winner(players);
    while (status == NO_WINNER) {

        int dummy;

        // In slow mode, we stop before every spin.
        if (SLOW_MODE) {
            printf("Player %d, it is your turn. Type 0 and enter to spin.\n", player_number+1);
            scanf("%d", &dummy);
        }

        // Get the current player's spin and print out her pieces.
        int square = get_spin();
        printf("Player %d, have landed on the square %s.\n", player_number+1, CHOICES[square]);
        update_player(players[player_number], square);
        print_player(players[player_number], player_number+1);

        // Update the game status.
        player_number = get_next_player(player_number);
        status = get_winner(players);
        printf("\n\n");
    }

    printf("Congrats player %d, you win!\n", status+1);

    return 0;
}

// Pre-conditions: player stores the contents of one player and square is in between 0 and 7, inclusive.
// Post-conditions: The turn for player will be executed with the given square selected.
void update_player(int player[], int square) {

    // Losing a piece
    if (square == 7) {

        /*** FILL IN CODE HERE ***/

        return;
    }

    // Restricted by having no plate!
    if (player[0] == 0) {

        /*** FILL IN CODE HERE ***/
    }

    // Process a regular case, where the player already has a plate.
    else {

        /*** FILL IN CODE HERE ***/
    }
}

// Pre-conditions: player stores the contents of one player that has at least one piece.
// Post-conditions: Executes asking a player which item they want to lose, and reprompts them
//                  until they give a valid answer.
int get_lost_piece(int player[]) {


    /*** POTENTIALLY FILL IN CODE HERE. ***/

    int choice;

    // Loop until a valid piece choice is made.
    while (1) {

        /*** FILL IN CODE HERE. ***/
    }

    return choice;
}

// Pre-conditions: piece_list stores the contents of one player
// Post-conditions: Returns 1 if choice is in between 0 and 6, inclusive and corresponds to
//                  an item in the piece_list. Returns 0 if choice is not valid or if the
//                  piece_list doesn't contain it.
int search(int piece_list[], int choice) {

    /*** FILL IN CODE HERE. ***/

}

// Pre-condition: None
// Post-condition: Returns a random value in between 0 and 7, inclusive.
int get_spin() {

    /*** FILL IN CODE HERE. ***/

}

// Pre-condition: None
// Post-condition: Initializes a player to have no pieces.
void init_player(int player[]) {

    /*** FILL IN CODE HERE. ***/

}

// Pre-condition: players stores the current states of each player in the tea party game.
// Post-condition: If a player has won the game, their 0-based player number is returned.
//                 In the case of no winners, -1 is returned.
int get_winner(int players[][NUMPIECES]) {

    /*** FILL IN CODE HERE. ***/
    return 7;

}

// Pre-condition: 0 <= player_num < NUMPLAYERS
// Post-condition: Returns the number of the next player, in numerical order, with
//                 a wrap-around to the beginning after the last player's turn.
int get_next_player(int player_num) {

    /*** FILL IN CODE HERE. ***/

}

// Pre-conditions: player stores the contents of one player
// Post-conditions: Returns the number of pieces that player has.
int count_pieces(int player[]) {

    /*** FILL IN CODE HERE. ***/

}

// Pre-conditions: player stores the contents of one player and player_num is that
//                 player's 1-based player number.
// Post-conditions: Prints out each item the player has, numbered with the numerical
//                  "codes" for each item.
void print_player(int player[], int player_num) {

    /*** FILL IN CODE HERE. ***/

}
