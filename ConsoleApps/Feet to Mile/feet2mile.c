// Robert Calero
// Feet to mile - C - Console Application

#include <stdio.h>

int main()
    {
        int feet_in_mile; // Variable declaration
        int yards_in_mile; // Variable declaration
        int feet_in_yard; // Variable declaration
          
        yards_in_mile = 1760; // Assigns a value to the variable
        feet_in_yard = 3; // Assigns a value to the variable
          
        feet_in_mile = yards_in_mile * feet_in_yard; // Multiplies 2 variables and assigns the value to another variable
          
        printf("Feet in a mile: %d\n", feet_in_mile); // Writes the variable value to the console and concatenates a string
        
        system("pause"); // This pauses the program
        return 0;
    }
