//implementation of linked list ADT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
	
void reverse (struct node**);
void createSorted (struct node**, char[]);
void display (struct node*);
void rotateleft (struct node*);
void sort (struct node**);
void dispMenu();

void reverse (struct node* *linklist) {
	struct node *prevNode = NULL, *currNode = *linklist, *nextNode = NULL;
	while (currNode!=NULL) {
		//store next
		nextNode = currNode->next;
		//reverse current node's pointer
		currNode->next = prevNode;
		//move pointers one position ahead
		prevNode = currNode;
		currNode = nextNode;
		}
	*linklist = prevNode;
	}
	
void createSorted (struct node* *linklist, char item[]) {
	//to sort list
	//sort(linklist);
	struct node *curr = *linklist, *prev = NULL;
	//if linked list does not exist, add item to list
	if (!(*linklist))
		insertFirst(linklist,item);
	//to find position node to insert new node
	while (curr!=NULL && (strcmp(curr->data,item)<0)) {
		prev = curr;
		curr = curr->next;
		}
	//to insert item into sorted list at the correct position
	if (prev==NULL)
		insertFirst(linklist,item);
	else if (curr==NULL)
		insertLast(linklist,item);
	else
		insertMiddle(linklist,prev->data,item);
	}

void rotateLeft (struct node* *linklist) {
	char item[SIZE];
	strcpy(item,deleteFirst(linklist,item));
	insertLast(linklist,item);
	}

void display(struct node* linklist) {
	printf("List: ");
	struct node* temp = linklist;
	if (!linklist) {
		printf("No names\n");
		return;
		}
	while(temp!=NULL) {
		printf("%s  ",temp->data);
		temp = temp->next;
		}
	printf("\n");
	}

int main() {
	//declaring linked list
	struct node* head = (struct node*) malloc(sizeof(struct node));
	head = NULL;
	
	//implementation of functions - menu form
	int choice;
	dispMenu();
	do {		
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice){
			case 1: {
				char item[SIZE];
				printf("Enter item to insert at the end of the list: ");
				scanf("%s", item);
				insertLast(&head,item);
				display(head);
				break;
				}
				
			case 2: {
				char item[SIZE];
				printf("Enter item to insert at the beginning of the list: ");
				scanf("%s", item);
				insertFirst(&head,item);
				display(head);
				break;
				}
				
			case 3: {
				char item1[SIZE];
				printf("Enter item1 (item after which item2 is to be inserted): ");
				scanf("%s", item1);
				char item2[SIZE];
				printf("Enter item2 (to be inserted after item1): ");
				scanf("%s", item2);
				insertMiddle(&head, item1, item2);
				display(head);
				break;
				}
				
			case 4: {
				char item[SIZE];
				strcpy(item,deleteLast(&head,item));
				if (strcmp(item,EMPTY)==0)
					printf("Invalid operation!\n");
				else
					printf("Deleted %s from the end of the list.\n", item);
				display(head);
				break;
				}
				
			case 5: {
				char item[SIZE];
				strcpy(item,deleteFirst(&head,item));
				if (strcmp(item,EMPTY)==0)
					printf("Invalid operation!\n");
				else
					printf("Deleted %s from the beginning of the list.\n", item);
				display(head);
				break;
				}
				
			case 6: {
				char item[SIZE];
				printf("Enter item to delete from the middle of the list: ");
				scanf("%s", item);
				deleteMiddle(&head,item);
				display(head);
				break;
				}
				
			case 7: {
				char item[SIZE];
				printf("Enter item to search for in the list: ");
				scanf("%s", item);
				if (search(&head,item)) 
					printf("Found\n");
				else 
					printf("Not found\n");
				break;
				}
				
			case 8: printf("Length of the linked list: %d\n", length(&head));
				break;
				
			case 9: printf("Data in the node pointed to by the pointer to linked list: %s\n", getData(&head));
				break;

			case 10: {
				printf("Displaying linked list:\n");
				display(head);
				break;
				}

			case 11: {
				printf("Reversing linked list...\n");
				reverse(&head);
				display(head);
				break;
				}
				
			case 12: {
				char item[SIZE];
				printf("Enter item to insert in the sorted list: ");
				scanf("%s", item);
				createSorted(&head,item);
				display(head);
				break;
				}
				
			case 13: {
				printf("Rotating the list anti-clockwise by 1...\n");
				rotateLeft(&head);
				display(head);
				break;
				}
				
			case 0: printf("Exiting the menu...\n");
				break;
			
			case -1: dispMenu();
				break;
				
			default: printf("Invalid option. Choice must be an integer in the range [0,9].\n"); break;
			}
			
		} while (choice != 0);
	return 0;
	}

void sort (struct node* *linklist) {
	printf("in\n");
	char item[SIZE];
	struct node *prevNode = NULL, *currNode = *linklist, *small = NULL, *temp = NULL;
	while (currNode!=NULL) {
		printf("in2\n");
		small = currNode;
		temp = currNode->next;
		while (temp!=NULL) {
			printf("in3\n");
			if (strcmp((temp->data),(small->data)) < 0) {
				small = temp;
				}
			temp = temp->next;
			}
		printf("out3\n");
		strcpy(item,small->data);
		printf("item: %s\n",item);
		if (small == currNode) {
			printf("inif\n");
			small = NULL;
			}
		else if (small->next == NULL) {
			printf("inelseif\n");
			small = NULL;
			strcpy(item,deleteLast(linklist,item));
			printf("item: %s\n",item);
			insertMiddle(linklist,prevNode->data,item);
			currNode = prevNode->next;
			}
		else {
			printf("inelse\n");
			small = NULL;
			deleteMiddle(linklist,item);
			printf("item: %s\n",item);
			insertMiddle(linklist,prevNode->data,item);
			currNode = prevNode->next;
			}
		prevNode = currNode;
		currNode = currNode->next;
		}
	printf("out2\n");
	//display(*linklist);
	}

void dispMenu() {
	printf("__MENU__\n");
	printf(" 1: insertLast()-insert item at end of list\n 2: insertFirst()-insert item at beginning of list\n");
	printf(" 3: insertMiddle()-insert item into middle of list\n 4: deleteLast()-delete last item of list\n");
	printf(" 5: deleteFirst()-delete first item of list\n 6: deleteMiddle()-delete item from middle of list\n");
	printf(" 7: searchInList()-search for an item in the list\n 8: lengthOfList()-find length of list\n");
	printf(" 9: getData()-find the item at the head of the list \n10: displayList()-display the list\n");
	printf("11: reverse()-reverse the list\n12: insertInSorted()-insert an item in the sorted list\n");
	printf("13: rotateLedt()-rotate the list to the left\n 0: exit menu\n-1: display menu\n");
	}

