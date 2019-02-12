#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "limits.h"

int main() {
  srand(time(0));
    //
    long int max_number = LONG_MAX -1;
    /*
    printf("Enter the max number: \n");
    scanf("%d", &max_number );
    */
    int secretNumber = ( rand()%max_number) + 1;
    long int guess;
    int guessRight = 0;
    int counter = 0;
    long int lowestHigh = max_number;
    int highestLow = 0;
    int bestguess;
    int Tguess = log2(max_number) + 1;
    printf("Max Guesses should be = %d out of a random number between 0 and %ld\n", Tguess, max_number);

    while(guess != secretNumber && guessRight == 0) {
      bestguess = (highestLow+lowestHigh)/2;
      //
      if(counter >= 1 && bestguess == guess){
        guess = bestguess+1;
      } else{
        guess = bestguess;
      }
      //
      printf("Your best bet is the number %d \n", bestguess);
      /* MUI
      printf("Enter Your Guess\n");
      scanf("%d", &guess);
      */

      if (guess <= 0){
        break;
      }
      counter++;
      if(guess == secretNumber){
        guessRight = 1;
      } else if(guess > secretNumber) {
        printf("Your guess of %ld is 2 high \n", guess);
        lowestHigh = guess;

      } else if(guess < secretNumber) {
        printf("Your guess of %ld is 2 low \n", guess);
        highestLow = guess;
      }
    }
    if(guessRight == 1){
      printf("You win with %d guesses taken\nThe number was %d \n", counter, secretNumber);
      printf("--------------------------------------\n");
    }
  return 0;
}
