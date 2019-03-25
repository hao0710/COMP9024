/**
     main.c

     Program supplied as a starting point for
     Assignment 1: Transport card manager

     COMP9024 18s2
**/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include "cardRecord.h"
#include "cardLL.h"

void printHelp();
void CardLinkedListProcessing();



int main(int argc, char *argv[]) {
   if (argc == 2) {
      // store the quantity of the cards which will be added in 
      int n=atoi(argv[1]);
      cardRecordT *record=malloc(n * sizeof(cardRecordT));
      assert (record!=NULL);
      for (int i=0;i<n;i++){
         record[i].cardID=readValidID();
         record[i].balance=readValidAmount();
      }
      float sum=0;// the sum of all cards
      float average;
      for (int j=0;j<n;j++){
         printCardData(record[j]);
         sum=sum+record[j].balance;
      }
      if (n==0){
         average=0;
      }
      else {
      average=sum/n;
      }
   printf("Number of cards on file: %d\n",n );
   if (average>=0){
   printf("Average balance: $%0.2f\n",average);
   }
   else{
      printf("Average balance: -$%0.2f\n",fabs(average));
   }
   free(record);

      /*** Insert your code for stage 1 here ***/
 
      
   } else { 
      CardLinkedListProcessing();
   }
   return 0;
}

/* Code for Stages 2 and 3 starts here */

void CardLinkedListProcessing() {
   int op, ch;
   int cardID=0;
   float balance=0;
   int quantity=0;
   float avg=0;

   List list = newLL();   // create a new linked list
   
   while (1) {
      printf("Enter command (a,g,p,q,r, h for Help)> ");

      do {
	 ch = getchar();
      } while (!isalpha(ch) && ch != '\n');  // isalpha() defined in ctype.h
      op = ch;
      // skip the rest of the line until newline is encountered
      while (ch != '\n') {
	 ch = getchar();
      }

      switch (op) {

         case 'a':
         case 'A':

         cardID=readValidID();
         balance=readValidAmount();
         insertLL(list, cardID, balance);
            /*** Insert your code for adding a card record ***/

	    break;

         case 'g':
         case 'G':
         balance=0;
         quantity=0;
         getAverageLL(list,&quantity,&balance);
         printf("Number of cards on file: %d\n",quantity);
         if (avg>=0){
         printf("Average balance: $%0.2f\n",balance);
         }
         else{
            printf("Average balance: -$%0.2f\n",fabs(balance));
         }  

            /*** Insert your code for getting average balance ***/

	    break;
	    
         case 'h':
         case 'H':
            printHelp();
	    break;
	    
         case 'p':
         case 'P':
            showLL(list);
        
            /*** Insert your code for printing all card records ***/

	    break;

         case 'r':
         case 'R':
            cardID=readValidID();
            removeLL(list,cardID);
            /*** Insert your code for removing a card record ***/

	    break;

	 case 'q':
         case 'Q':
            dropLL(list);       // destroy linked list before returning
	    printf("Bye.\n");
	    return ;
      }
   }
}

void printHelp() {
   printf("\n");
   printf(" a - Add card record\n" );
   printf(" g - Get average balance\n" );
   printf(" h - Help\n");
   printf(" p - Print all records\n" );
   printf(" r - Remove card\n");
   printf(" q - Quit\n");
   printf("\n");
}
