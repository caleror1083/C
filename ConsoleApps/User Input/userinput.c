// Robert Calero
// User input - C - Console Application

#include <stdio.h>

int main()
    {
        int age; // Variable declaration
          
        age = 0; // Assigns a value to the variable
        
        printf("How old are you: "); // Writes the string to the console and stays on the same line
        scanf("%d", &age); // gets input from user
          
        printf("You are %d years old\n", age); // Displays the input from the user to the console
        
        system("pause"); // This pauses the program
        return 0;
    }
