#ifndef NODEH
#define NODEH

// Define struct for nodes

struct NODE {
	int data;
	struct NODE *next;
};

// Function prototypes

void newList();
int addNode();
void prettyPrint();

#endif

