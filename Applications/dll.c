//implementation of doubly linked list ADT

#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

int shift (dll_ptr*,int,int);
void display (dll_ptr);
void dispMenu();

int shift (dll_ptr* DLL, int direction, int count) {
	if (direction!=1 && direction!=-1)
		return -1;
	if (count < 0)
		return -2;
	int skip = 0, item;
	if (direction == -1)
		while (skip < count) {
			item = deleteFirst(DLL);
			insertLast(DLL,item);
			skip++;
			}
	else if (direction == 1)
		while (skip < count) {
			item = deleteLast(DLL);
			insertFirst(DLL,item);
			skip++;
			}
	return 0;
	}

void display (dll_ptr DLL) {
	printf("List: ");
	if (!DLL) {
		printf("No names\n");
		return;
		}
	dll_ptr temp = DLL;
	do {
		printf("%d  ",temp->data);
		temp = temp->right;
		} while (temp != NULL);
	printf("\n");
	}

int main() {
	//declaring DLL
	dll_ptr l1 = NULL;
	
	//implementation of functions - menu form
	int choice;
	dispMenu();
	do {		
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice){
			case 1: {
				int item;
				printf("Enter integer item to insert at the end of the list: ");
				scanf("%d",&item);
				insertLast(&l1,item);
				display(l1);
				break;
				}
				
			case 2: {
				int item;
				printf("Enter integer item to insert at the beginning of the list: ");
				scanf("%d",&item);
				insertFirst(&l1,item);
				display(l1);
				break;
				}
				
			case 3: {
				int item = deleteLast(&l1);
				if (item == EMPTY)
					printf("Invalid operation! List is empty.\n");
				else
					printf("Deleted %d from the end of the list.\n", item);
				display(l1);
				break;
				}
				
			case 4: {
				int item = deleteFirst(&l1);
				if (item == EMPTY)
					printf("Invalid operation! List is empty.\n");
				else
					printf("Deleted %d from the beginning of the list.\n", item);
				display(l1);
				break;
				}
				
			case 5: {
				int dirn, count, result;
				printf("Enter direction in which to rotate list (-1 for left(AC), 1 for right(C)): ");
				scanf("%d",&dirn);
				printf("Enter no. of positions to rotate by (a positive integer): ");
				scanf("%d",&count);
				result = shift(&l1,dirn,count);
				if (result == 0)
					printf("Operation successfully completed. List rotated as specified.\n");
				else if (result == -1)
					printf("Invalid input! Direction must be entered as 1 or -1.\n");
				else if (result == -2)
					printf("Invalid input! No. of positions to rotate by must be a positive integer.\n");
				display(l1);
				break;
				}
				
			case 6: {
				printf("Displaying doubly linked list:\n");
				display(l1);
				break;
				}
				
			case 0: printf("Exiting the menu...\n");
				break;
			
			case -1: dispMenu();
				break;
				
			default: printf("Invalid option. Choice must be an integer in the range [-1,6].\n"); break;
			}		
		} while (choice != 0);
	
	return 0;
	}
	
void dispMenu() {
	printf("__MENU__\n");
	printf(" 1: insertLast()-insert item at end of list\n 2: insertFirst()-insert item at beginning of list\n");
	printf(" 3: deleteLast()-delete last item of list\n 4: deleteFirst()-delete first item of list\n");
	printf(" 5: shiftList()-rotate the list\n 6: displayList()-display the list\n");
	printf(" 0: exit menu\n-1: display menu\n");
	}
