#include<stdio.h>
#include<stdlib.h>
#include "list.h"

// Make private to this C file

static struct NODE *head; 

// newList initialises the head pointer to null 
	// head points to beginning of linked list
	// assumes there is a private global linked-list pointer called head 
 
void newList(){

	head = NULL;  
}

// addNode mallocs a new node for the scanf'd input number & stores value 
 
int addNode(int value){

	struct NODE *newNode;
	newNode = (struct NODE*)malloc(sizeof(struct NODE));

	newNode->data = value;

// changes position of head 
	if(head == NULL){
		newNode->next = NULL;
	}else{
		newNode->next = head;
	}

	head = newNode;

// informs if malloc succeeded or failed 

	if(newNode!= NULL){
		return (EXIT_SUCCESS);
	}else{
		printf("Malloc has failed.");
		return (EXIT_FAILURE);
	}
}

// prints the linked list (in reverse order) 

void prettyPrint(){
	
	struct NODE *newNode;
	newNode = head;
	
	printf("Head - ");
	while(newNode != NULL){
		printf("%d",newNode->data);
		newNode = newNode->next;
	}
	printf("- NULL \n");
}
