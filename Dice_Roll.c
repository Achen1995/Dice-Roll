#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Needed for function time
/*
 Addison Chen
*/

enum Status { CONTINUE, WON, LOST }; // game status

int rollDice(void); 

int main(void)
{ 
   // Random number generator using the current time
   srand(time(NULL));

   int myPoint; // Must make this point to win
   enum Status gameStatus; // This contain CONTINUE, WON, or LOST
   int sum = rollDice(); // first roll die

   // I used the switch statement to determine game status based on the sum of dice
   switch(sum) {

      // win on first roll
      case 7: // 7 win
      case 11: // 11 win          
         gameStatus = WON; 
         break;

      // lose on first roll
      case 2: // 2 lose
      case 3: // 3 lose
      case 12: // 12 lose
         gameStatus = LOST; 
         break;

      // remember point
      default:                  
         gameStatus = CONTINUE; // player should keep rolling
         myPoint = sum; // remember the point
         printf("Point is %d\n", myPoint);
         break; // optional
   } 

   // while game not complete
   while (CONTINUE == gameStatus) { // player should keep rolling
      sum = rollDice(); // roll dice again

      // determine game status
      if (sum == myPoint) { 
         gameStatus = WON; 
      } 
      else {
         if (7 == sum) { // lose by rolling an 7
            gameStatus = LOST; 
         } 
      } 
   }

   // display won or lost message
   if (WON == gameStatus) { 
      puts("Player wins");
   } 
   else { 
      puts("Player loses");
   } 
} 

int rollDice(void)// roll dice, calculate sum and display results
{
   int die1 = 1 + (rand() % 6); // random die1 value
   int die2 = 1 + (rand() % 6); // random die2 value

   // display results
   printf("Player rolled %d + %d = %d\n", die1, die2, die1 + die2);
   return die1 + die2; // return the sum of dice
} 
