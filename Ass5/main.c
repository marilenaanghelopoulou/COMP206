// COMP 206 Assignment #5 
// Marilena Anghelopoulou ID: 260530237

// after doing make to compile files, run program from command line ./program

#include<stdio.h>
#include "list.h"


int main() {

// initialise head to null 

	newList();

// read from stdin positive integers input by the user and add them to the linked list

	while(1){
		int number;
		printf("Type a positive integer greater than 0.\n");
		scanf("%d",&number);
		
		if(number <= 0){
			break;
		}

		addNode(number);

	}

// print linked list that will be in reverse order

	prettyPrint();

}
