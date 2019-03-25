// Linked list of transport card records implementation ... Assignment 1 COMP9024 18s2
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cardLL.h"
#include "cardRecord.h"
#include <math.h>
// linked list node type
// DO NOT CHANGE
typedef struct node {
    cardRecordT data;
    struct node *next;
} NodeT;

// linked list type
typedef struct ListRep {
   NodeT *head;//a pointer point to first NodeT
/* new more fields if you wish */

} ListRep;

/*** Your code for stages 2 & 3 starts here ***/

// Time complexity: O(1)
// Explanation: just input
List newLL() {
	ListRep *L=malloc(sizeof(ListRep));
	assert (L!=NULL);
	L ->head =NULL;
	return L;
  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: a single while loop went through the list
void dropLL(List listp) {
	NodeT *curr = listp->head;
    while (curr != NULL) {
        NodeT *temp = curr->next;
        free(curr);
        curr = temp;
    }
    free(listp);
   return;  /* needs to be replaced */
}
// Time complexity: O(n)
// Explanation: a single while loop that went through the list
void removeLL(List listp, int cardID) {
	NodeT *want_to_delete=listp->head;
	NodeT *before_delete=listp->head;
	//first senario the list is empty
	if (listp->head==NULL){
		printf("Card not found\n");
		return;
	}
	//second senario: the want to delete node is at the head of the list with only one node
	if (want_to_delete->next==NULL&&want_to_delete->data.cardID==cardID){
		printf("Card removed\n");
		free(want_to_delete);
		listp->head=NULL;

		return;
	}
	//third senario: the want to delete node is neither on the first nor the last node ,make special precedure for delete the nodes that at the head of the list
	while(want_to_delete!=NULL){
		if (want_to_delete->data.cardID==cardID){
			//if delete node is on the head of the list
			if(want_to_delete==before_delete){
				listp->head=before_delete->next;
				free(want_to_delete);
				return;
			}
			before_delete->next=want_to_delete->next;
			printf("Card removed.\n");
			free(want_to_delete);
			return;			
		}
		before_delete=want_to_delete;
		want_to_delete=want_to_delete->next;
	}
	// in the end if can't find the node; the id is not on the list
	if (want_to_delete==NULL){
		printf("Card not found.\n" );
	}
return;	
}


// Time complexity: O(n)
// Explanation: a while loop that go through the list
void insertLL(List listp, int cardID, float amount) {
	// create pointer
	NodeT *new=malloc(sizeof(NodeT));
	assert(new!=NULL);
	new ->data.cardID=cardID;
	new ->data.balance=amount;
	new ->next=NULL;
	//a pointer which used
	NodeT *current=listp->head;
	NodeT *node_before_insert=listp->head;
	//if the list is empty
	if (listp ->head ==NULL){
		listp ->head =new;
		//printf("bbbb\n");
		printf("Card added.\n");
		return;
	}
	while(current!=NULL){
		// insert at the front of the current node 
		if (current->data.cardID > new->data.cardID){
			if(current==node_before_insert){
				new->next=current;
				listp->head=new;
				printf("Card added.\n");
				return ;
			}
			new->next=current;
			node_before_insert->next=new;
			printf("Card added.\n");
			return ;
		}
		// id is equal
		if(current->data.cardID == new->data.cardID){
			current->data.balance=current->data.balance+amount;
			printCardData(current->data);
			//printf("bbbbbbbb\n");
			free(new);
			return;
		}
		node_before_insert=current;
		current=current->next;
	}
		//if(node_before_insert==NULL){
		//printf("here_1%d\n",node_before_insert->data.cardID );
		node_before_insert->next=new;
		printf("Card added.\n");
		return ;
			
}
// Time complexity: O(n)
// Explanation: a single loop go through the list hence it is in O(n)
void getAverageLL(List listp, int *n, float *balance) {
	int number_of_card=0;
	float total=0;
	float avg=0;
	NodeT *current=listp->head;// get a pointer which would travel to the end of the list
	for (current=listp->head;current!=NULL;current=current->next){
		number_of_card +=1;
		total=total+current->data.balance;
	}
	if (number_of_card==0){
		avg=0;
	}
	else{
   avg=total/number_of_card;
}
   *balance=avg;
   *n=number_of_card;
   return;  /* needs to be replaced */
}

// Time complexity: o(n)
// Explanation: a single for loop, We went though the list only once
void showLL(List listp) {
	NodeT *p=listp->head;
	for ( p =listp ->head; p!=NULL; p=p->next){
		printCardData(p->data);
	}

   return;  /* needs to be replaced */
}
