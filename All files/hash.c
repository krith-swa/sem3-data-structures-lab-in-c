//implementation of hash table
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "hash.h"

void display(htable);
void sumPairs (htable,int);

int main() {
	char cmd[50]; int ch=0;
	htable hash = createTable(15);
	
	//enter command as input from the user
	printf("\nEnter a command: ");
	scanf("%[^\n]s",cmd);
	
	char* token[2];
	token[0] = strtok(cmd," ");
	token[1] = strtok(NULL," ");
	
	do {
		if (strcmp(token[0],"insert")==0) {
			int key, value;
			value = atoi(token[1]);	
			key = value % hash->capacity;
			hash = insertValue(hash,key,value);
			}
		else if (strcmp(token[0],"display")==0) {
			display(hash);
			}
		else if (strcmp(token[0],"search")==0) {
			int key = atoi(token[1]);
			int result = search(hash,key);
			if (result == -1)
				printf("Value not found in table!\n\n");
			else
				printf("Value found is %d.\n\n",result);
			}
		else if (strcmp(token[0],"sum")==0) {
			int sum = atoi(token[1]);
			sumPairs(hash,sum);
			}
		else if (strcmp(token[0],"Sum")==0) {
			htable h = createTable(100);	
			int sum = atoi(token[1]);		
			sumPairs(h,sum);
			}
		else if (strcmp(token[0],"delete")==0) {
			int key = atoi(token[1]);
			int del = deleteValue(hash,key);
			if (del==0)
				printf("Value not found in table!\n");
			}
		else if (strcmp(token[0],"exit")==0) {
			ch=1;
			printf("Exiting the program...\n");
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

void display (htable h) {
	printf("Index\tValue\n");
	
	for (int i = 0; i < h->capacity; i++) {
		printf("  %d\t", i);
		if (h->arr[i] == NULL)
			printf("     \n");
		else if (h->arr[i]->value == -1)
			printf("     \n");
		else
			printf("%d\n", h->arr[i]->value);
		}
	}

void sumPairs (htable h, int sum) {
	int find=0;
	for (int i=0; i<sum/2; i++) {
		if (h->arr[i] != NULL) {
			int x = sum-(h->arr[i]->value);
			if (search(h,x) != -1 && h->arr[i]->value != h->arr[x]->value) {
				find=1;
				//printf("%d+%d\n",h->arr[i]->value,h->arr[x]->value);
				printf("%d + %d = %d\n", h->arr[i]->value, h->arr[x]->value, sum);
				}
			insertValue(h,h->arr[i]->value,h->arr[i]->value);
			}
		}
	if (find==0)
		printf("No such pairs exist\n");
	}
