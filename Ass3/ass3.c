#include <stdio.h>

// Marilena Anghelopoulou ID: 260530237
// COMP 206 Ass #3 


int main()	{

// Make array for message to be stored & define key	
	
	char input[101] = {'\0'};	 
	int key;
				
// Initialise arrays for encrypt & decrypt
	
	char encrypt[101] = {'\0'};
	char decrypt[101] = {'\0'}; 

// User enters input less than 100 chars

	printf("Enter your message for encryption (100 char max): \n");
	fgets(input,100,stdin);

// Ask user for the key
 
	printf("Enter desired key (left shift) for encryption:\n");

	int a = 0;
	int try = 0;


// Enter while loop to give user 4 attempts at key

	while (a < 5){
		if ( a == 4 ) {
			printf("You have run out of attempts. Please run the program again.\n"); 
			return 1;
		}

		if ( a != 0 ) {
			try = 4 - a;		
		printf("Insert key between 1-25. You have %d more tries left.\n",try);
		}

// Scan for user key 

	scanf("%d",&key);

		if (key <1 || key>25){ 
			a++;
		} else {
			break;
		}
	}

// Print original message		

	printf("Original message:%s",input);

// Encryption with a left shift 

// Initialising for encryption

	int i=0; 
	int newletter = 0;

// While loop to go through array and encrypt
	
	while (input[i] != '\0'){

// Accounts for spaces in message

		if (input[i] == 32){
			encrypt[i] = input[i];
			i++;		
			continue;
		}			
	        if (input[i] >= 'A' && input[i] <= 'Z'){
			newletter = input[i]- 'A';	// upper case letter 	
		}else if (input[i] >= 'a' && input[i] <= 'z'){
			newletter = input[i] - 'a';	//lower case letter
		}
// Avoids getting negative

		if (newletter - key < 0 ){
			encrypt[i] = input[i] + (26 - key);
		}else{
			encrypt[i] = input[i] - key;
		}
		i++; 
	}	

// Removes trash carried from before 
	encrypt[i-1] = '\0';
	
	printf("Encrypted message: %s\n",encrypt); 
		
// Decryption of message
	
	int k = 0; 
	int newLetter = 0;
	
	
	while (encrypt[k] != '\0') {
		if (encrypt[k] == 32){ 
			decrypt[k] = encrypt[k];

		} else if (encrypt[k] >= 'A' && encrypt[k] <= 'Z'){
			newLetter = encrypt[k] - 'A'; 
			decrypt[k] = (((newLetter + key) % 26) + 'A');
	
		} else if (encrypt[k] >= 'a' && encrypt[k] <= 'z'){
			newLetter = encrypt[k] - 'a';
			decrypt[k] = (((newLetter + key) % 26) + 'a');
		}
		k++;
	}
	
	printf("Decrypted message: %s\n",decrypt);
}
