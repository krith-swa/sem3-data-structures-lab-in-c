//implementation of AVL tree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

AVL addPhone (AVL avl, char* item);
void printDir (AVL avl);

int main() {
	printf("____TELEPHONE DIRECTORY MANAGER____\n");
	printf("(Each directory entry holds the name of the person and their telephone number.)\n\n");	
	
	char cmd[50]; int ch=0;
	AVL avl = NULL;
	
	//enter command as input from the user
	printf("Enter a command: ");
	scanf("%[^\n]s",cmd);
	
	//split command into 2 parts - instruction, entry
	char* token[2];
	token[0] = strtok(cmd," ");
	token[1] = strtok(NULL," ");
	
	do {
		if (strcmp(token[0],"insert")==0) {
			avl = addPhone(avl,token[1]);
			//printDir(avl);
			}
		else if (strcmp(token[0],"print")==0) {
			printDir(avl);
			}
		else if (strcmp(token[0],"search")==0) {
			int result = search(avl,token[1]);
			if (result == 1)
				printf("Entry found in directory!\n\n");
			else if (result == 0)
				printf("Entry not found in directory!\n\n");
			}
		else if (strcmp(token[0],"close")==0) {
			ch=1;
			printf("Exiting the directory...\n");
			exit(0);
			}
		else {
			printf("Invalid command!\n");
			exit(0);
			}
			
		for (int i=0; i<2; i++)
			if (token[i] != NULL)
				memset(token[i],0,strlen(token[i]));
		
		printf("Enter a command: ");
		scanf(" %[^\n]s",cmd);
		
		token[0] = strtok(cmd," ");
		token[1] = strtok(NULL," ");

		} while (ch==0);
	
	return 0;
	}

AVL addPhone (AVL avl, char* item) {
	return insert(avl,item);
	}
	

void printDir (AVL avl) {
	printf("\nDirectory:\n");
	inorder(avl);
	printf("\n");
	levelorder(avl);
	}

