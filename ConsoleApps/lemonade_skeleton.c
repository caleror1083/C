#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Symbolic constants to be used.

// Prices of bags of sugar and lemon, respectively.
#define PRICE_LEMON 3.50
#define PRICE_SUGAR 2.00

// Fraction of a bag of lemons and sugar used on a single cup of lemonade.
#define LEMON_PER_CUP 0.03
#define SUGAR_PER_CUP 0.04

// The initial loan the user is given to start their lemonade stand.
#define START_MONEY 20.00

// Using symbolic constants for true and false.
#define FALSE 0
#define TRUE 1

void buy_lemons(double *pLemons, double *pMoney);
void buy_sugar(double *pSugar, double *pMoney);
int weather();
int num_cups_sold(int weather, int cost);
void status_report(double cash, double num_lemons, double num_sugar, int day);
int max_sell(double num_lemons, double num_sugar);
int get_cost();
void sell_cups(double *pMoney, double *pLemons, double *pSugar);
void end_message(double money);

int main() {

  int num_day, ans;
  double money = START_MONEY, num_lemons = 0, num_sugar = 0;

  srand(time(0));

  printf("Welcome to the Game of Lemonade!\n\n");
  printf("You start the game with $%.2lf and no supplies!\n", START_MONEY);

  // Loop through each day. Ask the user if they want to buy lemons. If so,
  // carry out the transaction. Then ask them if they want to buy sugar.
  // If so, do this transaction as well. Then, let them sell lemonade for
  // the day. Finally, print a status report after they've sold lemonade
  // at the end of the day.
  for (num_day = 1; num_day <= 10; num_day++) {

  } 

  // Print out whether or not they have lost money, broke even or gained
  // money.


  return 0;
}

// Pre-conditions: pLemons and pMoney are pointers to variables that store
//                 the user's number of bags of lemons left and amount of
//                 money left.
// Post-condition: The user is given the opportunity to buy lemons. If 
//                 successful, the number of bags of lemons and the amount
//                 of money the user has are adjusted accordingly.
//
// What to do in this function: If the user doesn't have enough money to 
// even buy one bag of lemons, tell them so and return. Otherwise, ask
// the user how many bags of lemons they want to buy. If they answer less
// than one, tell them they must get more and reprompt them. If they 
// answer more than they can buy, tell them they don't have that much 
// money and reprompt them. Continue prompting them until they answer with
// a valid value. Then process the transaction.

void buy_lemons(double *pLemons, double *pMoney) {

}

// Pre-conditions: pSugar and pMoney are pointers to variables that store
//                 the user's number of bags of lemons left and amount of
//                 money left.
// Post-condition: The user is given the opportunity to buy sugar. If 
//                 successful, the number of bags of sugar and the amount
//                 of money the user has are adjusted accordingly.
//
// What to do in this function: If the user doesn't have enough money to 
// even buy one bag of sugar, tell them so and return. Otherwise, ask
// the user how many bags of sugar they want to buy. If they answer less
// than one, tell them they must get more and reprompt them. If they 
// answer more than they can buy, tell them they don't have that much 
// money and reprompt them. Continue prompting them until they answer with
// a valid value. Then process the transaction.

void buy_sugar(double *pSugar, double *pMoney) {

}

// Pre-condition: None
// Post-condition: The weather report for the day is printed and the
//                 corresponding weather status in between 1 and 5,
//                 inclusive, is returned.
int weather() {

  // Get the weather status value.
  int retval = rand()%5 + 1;

  printf("\nHere is today's weather forecast:\n");

  // Print out the appropriate forecast for that status.\n");
  if (retval == 1) 
    printf("It is cloudy with a high chance of rain.\n");
  else if (retval == 2)
    printf("It is partly cloudy and windy.\n");
  else if (retval == 3)
    printf("It is partly sunny with low humidity.\n");
  else if (retval == 4)
    printf("It is warm and sunny with medium winds.\n");
  else
    printf("It's a perfect beach day. Sunny and hot!\n");

  return retval; // Return this status value.
}

// Pre-condition: weather is an integer in between 1 and 5, inclusive,
//                standing for the weather status for the day. cost is
//                the cost of a cup of lemonade in cents for that day.
// Post-condition: The number of cups of lemonade for that day is returned.
int num_cups_sold(int weather, int cost) {

  int optimal_price, max_cups;
  double max_income;

  // Calculate a maximum revenue for the day.
  max_income = 5 + 3*weather;
  optimal_price = 15 + 5*weather;
  max_income = max_income - fabs(optimal_price - cost)/1.5;

  // If it's lower than 5 dollars, reset it to 5 dollars.
  if (max_income < 5)
    max_income = 5;

  // From this, determine the maximum number of cups that could be sold.
  max_cups = (int)(max_income/((double)cost/100));

  // Return a random number from 0 to this maximum.
  return rand()%(max_cups+1);

}

// Pre-condition: cash is the amount of cash the user has, num_lemons is
//                the number of bags of lemons the user has left, num_sugar
//                is the number of bags of sugar the user has left, and day
//                is which day of the game just finished.
// Post-condition: A status report with the four values passed in is nicely
//                 displayed for the user.
// 
// What to do with this function: This is fairly self-explanatory from the
// pre and post conditions. Look to the sample given in the assignment for
// the format.
void status_report(double cash, double num_lemons, double num_sugar, int day) {

}

// Pre-condition: pMoney, pLemons and pSugar are pointers to the variables
//                storing the user's amount of cash, number of bags of 
//                lemons and number of bags of sugar.
// Post-condition: A day's transactions will take place and the amount of
//                 money, the number of bags of lemons and sugar will be
//                 adjusted accordingly.
//
// What to do with this function: First prompt the user with the weather
// report. Then, ask the user for how much they want to sell a cup of 
// lemonade. Determine the number of cups that actually get sold for the
// day by determining how many cups the user COULD sell based on the
// availability of supplies and how many cups they COULD sell based on the
// weather. Print out how many cups of lemonade they ended up selling.
// Then adjust the amount of money they have, as well as the number of bags
// of lemons and sugar.

void sell_cups(double *pMoney, double *pLemons, double *pSugar) {

}

// Pre-condition: num_lemons is the number of bags of lemons the user has,
//                and num_sugar is the number of bags of sugar they have.
// Post-condition: The function returns the maximum number of cups of 
//                 lemonade the user can sell based on available supplies.
//
// What to do with this function: Calculate how many full cups of lemonade 
// you can supply with sugar. Do the same calculation for lemons. Then, 
// return the smaller of these two values.

int max_sell(double num_lemons, double num_sugar) {

}

// Pre-condition: None.
// Post-condition: Returns the number of cents the user will sell a cup of
//                 lemonade for, for that day.
//
// What to do with this function: Prompt the user to enter how much they
// want to charge for a cup of lemonade. If they don't enter a positive
// integer, reprompt them until they do. Then return this value.

int get_cost() {

}

// Pre-condition: money is the amount of money the user has left at the end
//                of the 10 days of running their Lemonade Stand.
// Post-condition: The user's overall loss or profit is printed out.

// What to do with this function: See if what they have left is less than
// what they started with. If so, print out how much the lost. If it's equal
// just print out a message saying that they broke even. Otherwise, print
// out how much profit they made!

void end_message(double money) {

}
