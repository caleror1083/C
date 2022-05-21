// Arup Guha
// 11/12/08
// Scaffold for 2008 Fall COP 3223 Program #5: Hangman

#include <stdio.h>

#define MAXSIZE 30
#define MAXWORDS 1000

void readWords(char allWords[][MAXSIZE], FILE *fin, int n);

int main() {
    
    char puzzles[MAXWORDS][MAXSIZE];
    char filename[MAXSIZE];
    FILE *fin;
    int numWords;
    
    // Ask the user for the input file.
    printf("What file stores the puzzle words?\n");
    scanf("%s", filename);   
    fin = fopen(filename, "r");
    
    // Read in all of the words into the array.
    fscanf(fin, "%d", &numWords);
    readWords(puzzles, fin, numWords);
    fclose(fin);
    
    // This will NOT be part of the final program, it's here
    // temporarily to show that the words have been read in.
    int i;
    printf("Here are all of the words.\n");
    for (i=0; i<numWords; i++) 
        printf("%s\n", puzzles[i]);    
    
    
    system("PAUSE");
    return 0;
}

// Pre-conditions: allWords must be of size n, at least, fin must
//                 point to a file with n words, with only uppercase letters
//                 ready to read from the first word.
// Post-conditions: The n words stored in the file pointed to by fin will
//                  we stored in the array allWords.
void readWords(char allWords[][MAXSIZE], FILE *fin, int n) {
     
     int i;
     for (i=0; i<n; i++)
         fscanf(fin, "%s", allWords[i]);
}
