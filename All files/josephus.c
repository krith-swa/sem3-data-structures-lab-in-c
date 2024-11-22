//josephus problem - implemented using circular doubly linked list ADT

#include <stdio.h>
#include <stdlib.h>
#include "cdll.h"

void emptyCircle(cdll_ptr*);
void createCircle(cdll_ptr*,int);
char findSafe(cdll_ptr,char,int);
void display(cdll_ptr);
void dispMenu();

void createCircle (cdll_ptr* CDLL, int number) {
	printf("\nEnter every soldier's label and the corresponding number chosen by them in the right order. Soldiers will be inserted one by one at the end of the list.\n");
	int num; char name;
	for (int i=0; i<number; i++) {
		printf("\tSoldier%d (A,B,C,...,Z): ",(i+1));
		scanf(" %c",&name);
		while ( (int)name < 65 || (int)name > 90 ) {
			printf("\tInvalid label! Enter soldier (A,B,C,...,Z): ");
			scanf(" %c",&name);
			}
		while (search(*CDLL,name)) {
			printf("\tSoldier already in circle! Enter unique label (A,B,C,...,Z): ");
			scanf(" %c",&name);
			}
		printf("\tPositive integer chosen: ");
		scanf("%d",&num);
		while (num <= 0) {
			printf("\tInvalid number! Enter positive integer chosen: ");
			scanf("%d",&num);
			}
		insertLast(CDLL,num,name);
		}
	}

void emptyCircle (cdll_ptr* CDLL) {
	while (*CDLL) {
		deleteNode(CDLL,(*CDLL)->label);
		}
	}

char findSafe (cdll_ptr CDLL, char startName, int startNum) {
	char soldier = startName;
	if (CDLL) {
		cdll_ptr tempCircle = NULL, curr = CDLL->right;
		do {
			insertLast(&tempCircle,curr->data,curr->label);
			curr = curr->right;
			} while (curr != CDLL->right);
		cdll_ptr temp = search(tempCircle,soldier), newStart;
		int sz = size(tempCircle), count = startNum, k;
		for (int i=1; i<sz; i++) { //while (CDLL->right != CDLL)
			if (i%2) {
				for (k=1; k<count; k++)
					temp = temp->right;
				newStart = temp->left;
				}
			else {
				for (k=1; k<count; k++)
					temp = temp->left;
				newStart = temp->right;
				}
			count = deleteNode(&tempCircle,temp->label);
			temp = newStart;
			}
		soldier = temp->label;
		free(tempCircle);
		}
	return soldier;
	}

void display (cdll_ptr CDLL) {
	printf("\n__CIRCLE__\n");
	if (!CDLL) {
		printf("No names\n");
		return;
		}
	cdll_ptr temp = CDLL->right;
	printf("Soldier: ");
	do {
		printf("%c  ",temp->label);
		temp = temp->right;
		} while (temp != CDLL->right);
	printf("\nInteger: ");
	do {
		printf("%d  ",temp->data);
		temp = temp->right;
		} while (temp != CDLL->right);
	printf("\n");
	}

int main() {
	//initialising gameplay
	cdll_ptr circle = NULL;
	
	int choice;
	dispMenu();
	do {		
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		
		switch (choice){
			case 1: {
				int nOfSoldiers;
				circle = NULL;
				printf("\nEnter no. of soldiers in the circle: ");
				scanf("%d",&nOfSoldiers);
				createCircle(&circle,nOfSoldiers);
				display(circle);
				break;
				}
			
			case 2: {
				emptyCircle(&circle);
				display(circle);
				break;
				}
				
			case 3: {
				char startName; int startNum;
				printf("Enter the soldier to start with: ");
				scanf(" %c",&startName);
				if (!(search(circle,startName))) {
					printf("Invalid entry! Soldier not found in circle or circle does not exist.\n");
					break;
					}
				printf("Enter positive integer to start with: ");
				scanf("%d",&startNum);
				if (startNum <= 0) {
					printf("Invalid entry! Number entered must be a positive integer.\n");
					break;
					}
				
				//to find the soldier who escapes
				char safe = findSafe(circle,startName,startNum);
				printf("The soldier who escapes is %c.\n",safe);
				break;
				}
			
			case 4: {
				display(circle);
				break;
				}
				
			case 0: printf("Exiting the menu...\n");
				break;
			
			case -1: dispMenu();
				break;
				
			default: printf("Invalid option. Choice must be an integer in the range [-1,4].\n"); break;
			}		
		} while (choice != 0);
	
	return 0;
	}
	
void dispMenu() {
	printf("\n__INTRODUCTION__\n");
	printf("A group of soldiers is surrounded by an overwhelming enemy force. There is no hope for victory without reinforcement, but there is a single horse available for escape. The soldiers agree to a pact to determine which one of them is to escape and summon help. They stand in a circle and each one chooses a positive integer. One of their names and a positive integer ‘n’ are chosen. Starting with the person whose name is chosen; they count around the circle clockwise and eliminate the nth person. The positive integer which that person chose is then used to continue the count, but this time in the anticlockwise direction. Each time that a person is eliminated, the number the person chosen is used to determine the next person to be eliminated and the direction of traversal is opposite to that of the previous one. i.e. the counting alternates between clockwise and anticlockwise direction.\n");
	printf("\n__INSTRUCTIONS__\n");
	printf("Create different circles of soldiers and start the play with different soldiers and integers to find the soldier who escapes in each scenario.\n");
	printf("\n__MENU__\n");
	printf(" 1: createCircle()-create a circle of soldiers\n 2: emptyCicle()-empty the circle of all soldiers\n");
	printf(" 3: findSafeSoldier()-find the soldier who escapes\n 4: displayCircle()-display the circle\n");
	printf(" 0: exit the play\n-1: display menu\n");
	}
	
/*
char findSafe (cdll_ptr CDLL, char startName, int startNum) {
	char soldier = startName;
	if (CDLL) {
		cdll_ptr temp = search(CDLL,soldier), newStart;
		int sz = size(CDLL), count = startNum, k;
		for (int i=1; i<sz; i++) { //while (CDLL->right != CDLL)
			if (i%2) {
				for (k=1; k<count; k++)
					temp = temp->right;
				newStart = temp->left;
				}
			else {
				for (k=1; k<count; k++)
					temp = temp->left;
				newStart = temp->right;
				}
			count = deleteNode(&CDLL,temp->label);
			display(CDLL);
			temp = newStart;
			}
		soldier = temp->label;
		}
	return soldier;
	}
*/
