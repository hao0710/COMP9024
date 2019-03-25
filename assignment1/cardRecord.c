// Transport card record implementation ... Assignment 1 COMP9024 18s2
#include <stdio.h>
#include "cardRecord.h"
#include <math.h>
#define LINE_LENGTH 1024
#define NO_NUMBER -999

// scan input line for a positive integer, ignores the rest, returns NO_NUMBER if none
int readInt(void) {
   char line[LINE_LENGTH];
   int  n;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%d", &n) != 1) || n <= 0 )
      return NO_NUMBER;
   else
      return n;
}

// scan input for a floating point number, ignores the rest, returns NO_NUMBER if none
float readFloat(void) {
   char  line[LINE_LENGTH];
   float f;

   fgets(line, LINE_LENGTH, stdin);
   if (sscanf(line, "%f", &f) != 1)
      return NO_NUMBER;
   else
      return f;
}

int readValidID(void) {

   printf("Enter card ID: ");
   int cardID=readInt();
   while (cardID== NO_NUMBER||cardID < 10000000 || cardID > 99999999){
      printf("Not valid. Enter a valid value: ");
      cardID=readInt();
   }

   return cardID;  /* needs to be replaced */
}

float readValidAmount(void) {
   printf("Enter amount: ");
   float amount=readFloat();
   while (amount<=-2.35 || amount>=250){
      printf("Not valid. Enter a valid value: ");
      amount=readFloat();
   }
   return amount;  /* needs to be replaced */
}

void printCardData(cardRecordT card) {
   printf("-----------------\n");
   printf("Card ID: %d\n",card.cardID);
   if (card.balance<5 && card.balance>=0){
      printf("Balance: $%0.2f\n",card.balance);
      printf("Low balance\n");
      printf("-----------------\n");
   }
   else if (card.balance<0){
   	
   	printf("Balance: -$%0.2f\n",fabs(card.balance));
   	printf("Low balance\n");
     printf("-----------------\n");

   }
   else{
      printf("Balance: $%0.2f\n",card.balance);
      printf("-----------------\n");
   }


   return;  /* needs to be replaced */
}
