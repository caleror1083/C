// Arup Guha
// Skeleton to COP 3223 Fall 2006 Program #6
// This skeleton implements creating the tiles for the game, the board, and
// randomly picking 7 tiles for the user.

// For program #6, you should add in the functionality of taking the word the
// user has entered and verifying if it can be formed with the tiles he/she
// has. Then, if this is possible, ask the user where to place the word on the
// board and then determine the score for just that word in the location it is
// being placed.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for the sizes of various objects.
#define SIZE 15
#define NUMTILES 7
#define TOTALTILES 100

// Constants for the word orientation.
#define DOWN 0
#define ACROSS 1

// Constants for the all the game squares.
#define TRIPLE_WORD 'T'
#define DOUBLE_WORD 'D'
#define TRIPLE_LETTER 't'
#define DOUBLE_LETTER 'd'
#define REGULAR '_'

// Constant to represent the blank tile.
#define BLANK 'b'

// Stores a single tile for the game.
struct tile {
    char letter;
    int score;
};


// Stores the whole bag of tiles.
struct bag {
    struct tile all[TOTALTILES];
    int quantity;
};

void fillBoard(char emptyBoard[][SIZE]);
void fillSquareSymmetry(char board[][SIZE], int x, int y, char sq);
void printBoard(char board[][SIZE]);
void fillBag(struct bag *b);
int getScore(char c);
struct tile* pickTile(struct bag *b);
void printTiles(struct tile t[], int length);
void copyTile(struct tile *dest, const struct tile *source);
void processCase(struct tile tiles[], int length, char scrabble[][SIZE]);
int valid(struct tile tiles[], char word[]);
int getWordScore(char word[], char myscrabble[][SIZE], int x, int y, int direction);

int main() {
    
    char myscrabble[SIZE][SIZE];
    struct tile mytiles[NUMTILES];
    struct bag mybag;
    int i;
    
    srand(time(0));
    
    // Set up the game.
    fillBoard(myscrabble);
    printBoard(myscrabble);
    fillBag(&mybag);
    
    // Get 7 tiles for your hand.
    for (i=0; i<NUMTILES; i++)
        copyTile(&mytiles[i], pickTile(&mybag));
    
    // Print out the tiles and process a single case.
    printTiles(mytiles, NUMTILES);
    processCase(mytiles, NUMTILES, myscrabble);
           
    system("PAUSE");
    return 0;        
}

// Processes a case where tiles stores the users tiles, length is the length
// of the tiles array, and scrabble is the representation of the board.
void processCase(struct tile tiles[], int length, char scrabble[][SIZE]) {

    char word[SIZE];
    
    // Get the word from the user to play.
    printf("\nPlease enter a word you would like to form.\n");
    scanf("%s", word);
    
    // Check if the word is valid.
    if (valid(tiles, word)) {
       
       int x, y, direction;
       
       // Get the location and orientation of the word to be placed.
       printf("Where would you like to place the word?\n");
       printf("Enter the starting row coordinate(0-14).\n");
       scanf("%d", &x);
       printf("Enter the starting column coordinate(0-14).\n");
       scanf("%d", &y);
       
       printf("Would you like the word going down(0) or across(1)?\n");
       scanf("%d", &direction);
       
       // Fill in code here, check for invalid word locations
       
       // Otherwise, score the word! (Fill in this part also.)
    }
    
    // You don't have the tiles to make this word!
    else {
       printf("Sorry, you do not have the tiles to make that word.\n");
    }
}

// Checks if all the letters in word appear in tiles. 
// Returns 1 if the letters are there, 0 otherwise.
int valid(struct tile tiles[], char word[]) {
    
    int i,j;
    int d[NUMTILES];
    for (j=0; j<NUMTILES; j++)
        d[j] = 0;
        
    for (i=0; i<strlen(word); i++) {
        for (j=0; j<NUMTILES; j++) {
            
            if (d[j] == 0 && word[i] == tiles[j].letter) {
               d[j] = 1;
               break;
            }
        }
    }
    
    // Figure out # of ones in the array d.
    int numones = 0;
    printf("\n");
    for (j=0; j<NUMTILES; j++) {
        numones = numones + d[j];
        printf("%d ", d[j]);
    }
    printf("\n");
        
    if (numones == strlen(word))
       return 1;
    else
       return 0;
       
}

// Returns the score of playing word on the myscrabble board if we position
// word at coordinates x,y, and moving in direction.
int getWordScore(char word[], char myscrabble[][SIZE], int x, int y, int direction) {
                     
}

// Fills an empty Scrabble board with it's initial values.
void fillBoard(char emptyBoard[][SIZE]) {
     
     int row, col;
     
     // Initialize the board to all regular squares.
     for (row = 0; row < SIZE; row++)
         for (col = 0; col < SIZE; col++)
             emptyBoard[row][col] = REGULAR;
             
     // Fill in all triple word score squares.
     fillSquareSymmetry(emptyBoard, 0, 0, TRIPLE_WORD);
     fillSquareSymmetry(emptyBoard, 0, SIZE/2, TRIPLE_WORD);
     fillSquareSymmetry(emptyBoard, SIZE/2, 0, TRIPLE_WORD);
     
     // Fill in the middle double word score.
     emptyBoard[SIZE/2][SIZE/2] = DOUBLE_WORD;
     
     // Fill in the rest of the double word score squares.
     for (row = 1; row < 5; row++) 
         fillSquareSymmetry(emptyBoard, row, row, DOUBLE_WORD);
     
     // Fill in all of the triple letter score squares.
     fillSquareSymmetry(emptyBoard, 1, SIZE/3, TRIPLE_LETTER);
     fillSquareSymmetry(emptyBoard, SIZE/3, 1, TRIPLE_LETTER);
     fillSquareSymmetry(emptyBoard, SIZE/3, SIZE/3, TRIPLE_LETTER);
     
     // Fill in all of the double letter score squares.
     fillSquareSymmetry(emptyBoard, 0, SIZE/5, DOUBLE_LETTER);
     fillSquareSymmetry(emptyBoard, SIZE/5, 0, DOUBLE_LETTER);
     fillSquareSymmetry(emptyBoard, 2, 2*SIZE/5, DOUBLE_LETTER);
     fillSquareSymmetry(emptyBoard, 2*SIZE/5, 2, DOUBLE_LETTER);
     fillSquareSymmetry(emptyBoard, 2*SIZE/5, 2*SIZE/5, DOUBLE_LETTER);
     fillSquareSymmetry(emptyBoard, SIZE/5, SIZE/2, DOUBLE_LETTER);
     fillSquareSymmetry(emptyBoard, SIZE/2, SIZE/5, DOUBLE_LETTER);
}

// Fills location x,y with the value sq, as well as the three "mirror"
// locations assuming symmetry around the lines x=7 and y=7.
void fillSquareSymmetry(char board[][SIZE], int x, int y, char sq) {
     board[x][y] = sq;
     board[x][SIZE-1-y] = sq;
     board[SIZE-1-x][y] = sq;
     board[SIZE-1-x][SIZE-1-y] = sq;     
}

// Prints out the board.
void printBoard(char board[][SIZE]) {
     
     int row, col;
     
     printf("Here is a print out of the scrabble board with row and column\n");
     printf("numbers as well as the locations of all of the special squares.\n\n");
     
     // Print the column headers.
     printf("%4c", ' ');
     for (col = 0; col<SIZE; col++)
         printf("%4d", col);
     printf("\n");
     
     // Print each row.
     for (row = 0; row<SIZE; row++) {
         
         // Print a row header for each row.
         printf("%4d", row);
         
         // Print each element of the current row.
         for (col = 0; col<SIZE; col++)
             printf("%4c", board[row][col]);
             
         // Go to the new line.
         printf("\n");
     }     
     
     printf("\n");
}

// Fills the bag pointed to by b.
void fillBag(struct bag *b) {
     
     // Frequencies of all of the letters in scrabble.
     int letterfreq[26] = {9, 2, 2, 4, 12, 2, 3, 2, 9, 1, 1, 4, 2, 
                       6, 8, 2, 1, 6,  4, 6, 4, 2, 2, 1, 2, 1};
     
     int letter, freq, cnt = 0;
     
     // Fill in the bag with all of the letters.
     
     // Go through each letter.
     for (letter=0; letter<26; letter++) {
         
         // Put in the correct number of tiles with the current letter.
         for (freq=0; freq<letterfreq[letter]; freq++) {
             b->all[cnt].letter = (char)(letter+'A');
             b->all[cnt].score = getScore(b->all[cnt].letter);
             cnt++;
         }
     } 
     
     // Manually fill in the two blanks.
     b->all[cnt].letter = BLANK;
     b->all[cnt].score = getScore(b->all[cnt].letter);
     b->all[cnt+1].letter = BLANK;
     b->all[cnt+1].score = getScore(b->all[cnt].letter);
     b->quantity = TOTALTILES;
     
}

int getScore(char c) {
    
    // This function just does brute force, since there's no real easy 
    // pattern behind the scores for each letter...
    
    if (c == 'D' || c == 'G')
       return 2;
    if (c == 'B' || c == 'C' || c == 'M' || c == 'P')
       return 3;
    if (c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y')
       return 4;
    if (c == 'K')
       return 5;
    if (c == 'J' || c == 'X')
       return 8;
    if (c == 'Q' || c == 'Z')
       return 10;
    if (c == BLANK)
       return 0;
          
    return 1;
}

// Returns a pointer to a tile randomly chosen from the bag pointed to by b.
// The bag is adjusted accordingly.
struct tile* pickTile(struct bag *b) {
    
       // Get the random index into the bag.   
       int randnum = rand()%(b->quantity);
       
       // Allocate space for the tile to be returned.
       struct tile* retval;
       retval = malloc(sizeof(struct tile));
       
       // Set up retval to be the randomly chosen tile.
       copyTile(retval, &(b->all[randnum]));
       
       // Copy over where retval used to be stored with the last element.
       copyTile(&(b->all[randnum]), &(b->all[b->quantity-1]));
       
       // Adjust the number of tiles in the bag pointed to by b.
       b->quantity = b->quantity - 1;
       return retval;
}

// Copies the tile pointed to by source into the tile pointed to by dest.
void copyTile(struct tile *dest, const struct tile *source) {
     dest->letter = source->letter;
     dest->score = source->score;
}

// Prints out the first length tiles of t.
void printTiles(struct tile t[], int length) {
     int i;
     printf("Here are your tiles, letter & score: ");
     
     // Print out the first length-1 tiles.
     for (i=0; i<length-1; i++)
        printf("%c %d, ", t[i].letter, t[i].score);     

     // Print out the last one without a comma at the end.
     printf("%c %d\n", t[i].letter, t[i].score);
}
