#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include "queue.h"
#include "Graph.h"

int* digits(int a){
	int lenth=floor(log10(abs(a))) + 1;
	int temp=a;
	int *digits = malloc(sizeof(int) *lenth);
	for (int i=0;i<lenth;i++){
		digits[i]=temp%10;
		temp=temp/10;
	}
	return digits;
}

// check if the integer a appear in interger b
int check_digit(int a,int p){
	int lenth_a = floor(log10(abs(a))) + 1;// simple mathematic to calculate the lenth of the digit
	int lenth_p=floor(log10(abs(p))) + 1;
	int *digitsa=digits(a);
	int *digitsp=digits(p);
	int flag=1;
	for ( int i=0;i<lenth_a;i++){ 
		int match =0; 
		for ( int j=0;j<lenth_p;j++){
			if (digitsp[j]==digitsa[i]){
				match=1;}
		}
		if(match == 0){
			flag = 0;}
	}
	//printf("flag is %d\n",flag);
	free(digitsa);
	free(digitsp);
return flag;
}
//get all tge diversors of p, return pointers
int *find_diversor(int p){
	int tmp_diversor;
	int count=0;
	int i=0;
	queue queue=newQueue();
	for(tmp_diversor=1;tmp_diversor<=p;tmp_diversor++){
		if (p%tmp_diversor==0){
			count++;
			QueueEnqueue(queue, tmp_diversor);
			}
	}
	int *diversor=malloc(sizeof(int )*count);
	while(!QueueIsEmpty(queue)){
		diversor[i++]=QueueDequeue(queue);
		}
	dropQueue(queue);
return diversor;
}
// get the number of diversors
int n_diversor(int p){
	int diversor;
	int count=0;
	for (diversor=1;diversor<=p;diversor++){
		if(p%diversor==0){
			count++;}
	}
	return count;
}

int main(int argc, char * argv[]){
	int p;
    sscanf(argv[1], "%d", &p);
    int n=n_diversor(p);
    int *diversor=find_diversor(p);
    Graph g=newGraph(n);
    Edge e;
    printf("Partial order:\n");
    //if the partial order which they are not all should be printed
    for(int i = 0; i < n; i ++){
    	printf("%d: ",diversor[i]);
        for(int j =i+1; i <=j&&j<n; j ++){
            if(diversor[j] % diversor[i] == 0 && check_digit(diversor[i],diversor[j])==1){
            	e.v=i;
            	e.w=j;
            	insertEdge(g,e);
           		printf("%d ", diversor[j]);
           }
        }
      printf("\n");
     }
    queue path;
    path=find_path(g);
    printf("\n");
    printf("Longest monotonically increasing sequences:\n");
    while(!QueueIsEmpty(path)){
    	int i=QueueDequeue(path);
     	if (get_queue_lenth(path)==0){
     		printf("%d \n",diversor[i]);
     	}
     	else{
     		printf("%d < ",diversor[i]);
     	}
     	
     }
dropQueue(path);
freeGraph(g);
free(diversor);
return 0;
}    
