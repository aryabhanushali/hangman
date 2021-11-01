/*
Arya Bhanushali
20 October
CS50AP Period 6
Structures in C
*/

//Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

struct hangmanStruct {

    int roundNum;
    int score;
    string word;
};

//Main Method
int main(int argc, char *argv[]) {

  //file pointer
  FILE *fp;

  //opens and creates text file in which one can read and write
  fp = fopen("hangmanOutputBhanushali.txt", "w+");

    //statement that is outputted when file could not be opened
    if (fp == NULL){
        printf("Could not open file.");
        return 1;
    }

  //user inputs name
  char name[50];
  printf("Enter your name: ");
  scanf("%s", name);


  //struct consisting of 3 data pieces and 2 datatypes: int, string
  struct hangmanStruct structRoundOne = { 1, 0, "winter"};

  //sets variable answer equal to the string in the struct
  string answer = structRoundOne.word;

  //sets variable num equal to length of the variable "answer"
  int num = strlen(answer);
  printf("Word has %d letters.\n", num);

  //set array for the game where characters are guessed
  int gamemode [num];

  //for loop where if characters is guessed, game will end
  //i=0 will execute after ++i
  for (int i=0; i < num; ++i) {
    gamemode[i] = 0;
  }
  int game_over = 0;
  //while the statement is false, the game will not end and user may continue to guess
  while (! game_over) {



   //for loop that prints the character guessed by user and '-' for unguessed characters
    for(int a=0; a < num; ++a) {
        if (gamemode[a]) {
        printf("%c", answer[a]);
      }
      else {
        printf("-");
      }
    }
    printf("\n");


    //initializes char guess from user input
    char letter;
    printf("What's your guess? \n\n");
    scanf(" %c", &letter);

    //identifies guess in its correspondance to word and continues loop
    for(int g=0; g < num; ++g) {
      if (answer[g] == letter) {
	gamemode[g] = 1;
      }
    }
  //stops looping if statement is false
   game_over = 1;
    for(int m = 0; m < num; ++m) {
      if (!gamemode[m]) {
        game_over = 0;

      }
    }
  }




  // outputs message once user guesses whole word
  printf("Good Job!! The word is \"%s\".\n", answer);

  //edits struct in file
  structRoundOne.score=1;

  //prints struct with game stats into file
  fprintf(fp, "player: %s\n Round: %i\n Score:  %i\n", name, structRoundOne.roundNum, structRoundOne.score);

  //closes file
  fclose(fp);

  return(0);

}




































Enter your name: Arya
Word has 6 letters.
------
What's your guess? 

w
w-----
What's your guess? 

i
wi----
What's your guess? 

n
win---
What's your guess? 

r
win--r
What's your guess? 

d
win--r
What's your guess? 

t
wint-r
What's your guess? 

e
Good Job!! The word is "winter".
~/cs50/ $ 


