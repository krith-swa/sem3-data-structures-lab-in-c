#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void insertafterdata (int a[], int data1, int data2) {
	if (data2!=DELIM) {
		int length=size(a);
    		int i=0, foundAt;
    		do {
      			foundAt=search(a,i,data1);
      			//printf("Found at: %d\n",foundAt);
      			if (foundAt!=-1) {
        			length=insertAt(a,length,foundAt+1,data2);
        			//printf("New size: %d\n",length);
        			i=foundAt+2;
        			}
      			} while (i!=length && foundAt!=-1);
    		}
  	else
    		printf("Do not enter the delimiter into the array!\n");
	}
	
void printArray(int a[]) {
	printf("Array: ");
	for (int i=0; i<size(a); i++) {
		printf("%d ",a[i]);
		}
	printf("\n");
	}

int main () {
	//part a
	int data1, data2, A[MAX_SIZE], i=-1, pos;

  	printf("Enter array elements:\n");
  	do {
    		i++;
    		scanf("%d",&A[i]);
  		} while(A[i]!=DELIM);
		
  	//to check size of array
  	//printf("Size of array: %d\n",size(A));

  	//to print original array
  	printArray(A);

	//part b
	printf("Enter data1 (number after which reqd number is to be inserted): ");
	scanf("%d",&data1);
	printf("Enter data2 (data to be inserted): ");
	scanf("%d",&data2);

	//validation
		//search function
	/*for (i=1; i<=4; i++) {
		printf("Testing search. Enter position to search from: ");
		scanf("%d",&pos);
		int ret=search(A,pos,data1);
		if (ret==-1)
			printf("Data not found in array.\n");
		else if (ret==-2)
			printf("Cannot search as position entered is negative. Position must be positive and within the array bounds.\n");
		else if (ret==-3)
			printf("Cannot search as position entered is greater than the size of the array. Position must be positive and within the array bounds.\n");
		else
			printf("Found at index: %d\n",ret);
		}
		//insert function
	for (i=1; i<=3; i++) {
		printf("Testing insert. Enter position to insert at: ");
		scanf("%d",&pos);
		int ret=insertAt(A,size(A),pos,data2);
		if (ret==-1)
			printf("Insert operation was unsuccessful.\n");
		else if (ret==-2)
			printf("Cannot insert as position entered is negative. Position must be positive and within the array bounds.\n");
		else if (ret==-3)
			printf("Cannot insert as position entered is greater than the size of the array. Position must be positive and within the array bounds.\n");
		else
			printf("Size after inserting: %d\n",ret);
		}*/


	//function call to insert data in reqd positions of array
	insertafterdata(A,data1,data2);
	
  	//part c
	//function to print new array
	printArray(A);

	return 0;
	}
