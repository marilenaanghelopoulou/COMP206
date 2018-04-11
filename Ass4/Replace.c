#include <stdlib.h>
#include <stdio.h>

//Marilena Anghelopoulou ID:260530237
//COMP 206 Ass 4


// FindRecord opens the file and reads each record looking for matching record name. Return matching record in array record[]. Closes file.

void FindRecord(char *filename,char *name,char record[]){

	// Initialise variable that stores current record being checked

	char currentRec[1000] = {'\0'};

	// Open file and points to first term in file

	FILE *file = fopen(filename,"r");

	// Is the CSV file there?

	if  (file == NULL){
		printf("File name not valid. This file doesnt exist.");
		exit(1);
	}
	
	// Check until we reach the end of CSV file 
	
	int i;
	while(!feof(file)){
		i=0;
		fgets(currentRec,1000,file);
		while(1){
			
			// If first letter doesnt match or if comma skip record
 
			if(name[i]!= currentRec[i] || currentRec[i]==','){
				break;
			}
			// If at end of name and end currentRec = match , so copy into record
		
			if(name[i+1]=='\n' && currentRec[i+1]==','){
				for(int j=0;j<1000;j++){
					record[j]=currentRec[j];
				}
				printf("Record found: %s",record); 

				fclose(file);	
				
				return;
			}
			i++;
		}
	}
	printf("Name not found. Please run the program again with a different name\n");
	exit(1);
}

// Replace replaces the name in the array record[] with newname. Updated info returned in array record[]. Using pointers.

void Replace(char *name, char *newname, char record[]){
	char tmp[1000];
	int i=0;int j=0;int ii=0;int jj=0;
	
	// Go until end of name in record 

	while(*(record + i)!=','){
		i++;
	}
	// Copy all after name into temp

	while(i<1000){
		*(tmp+j)=*(record+i);
		i++; j++;
	}

	// Add new name to the record 

	while(*(newname+ii)!='\n'){
		*(record+ii)=*(newname+ii);
		ii++;
	}

	// Add all from temp after new name to make new record  

	while(ii<1000 && jj<1000){
		*(record+ii)=*(tmp+jj);
		ii++; jj++;
	}
	printf("Record replaced: %s",record); 
}

//SaveRecord replaces record in CSV that matches name with the array record[]. Closes file.

void SaveRecord(char *filename,char *name,char record[]){
	char currentRec[1000] = {'\0'};

	//open file and points to first term in file

	FILE *file = fopen(filename,"r");
	FILE *tmpFile  = fopen("tmp.csv","w+");

	// until we reach the end of file 
	
	fgets(currentRec,1000,file);

	int i;
	while(!feof(file)){
		i=0;
		while(1){
			// If name doesnt match current record read, then copy current record to tmp file
			if(name[i]!= currentRec[i] || currentRec[i]==','){
				fputs(currentRec,tmpFile);
				break;
			}
			// If name matches current record, then copy replaced record to tmp file 
			if(name[i+1]=='\n' && currentRec[i+1]==','){
				fputs(record,tmpFile);
				break;
			}
			i++;
		}
		fgets(currentRec,1000,file);
	}

	fclose(file);
	fclose(tmpFile);

// Replace with new record 
	
	file    = fopen(filename,"w+");
	tmpFile = fopen("tmp.csv","r");

// Read from tmpFile into currentRec, put currentRec into file
 
	fgets(currentRec,1000,tmpFile);
	while(!feof(tmpFile)){
		fputs(currentRec,file);
		fgets(currentRec,1000,tmpFile);
	}
	fclose(file);
	fclose(tmpFile);	
}

int main() {

// declare variables
	
	char record[1000]= {'\0'};
	char name1[1000]= {'\0'};
	char newname[1000]= {'\0'};

	printf("Please input name\n");
	fgets(name1,1000,stdin);

	FindRecord("phonebook.csv",name1,record);
	
	printf("Please input new name\n");
	fgets(newname,1000,stdin);

	Replace(name1,newname,record);

	SaveRecord("phonebook.csv",name1,record);
}
