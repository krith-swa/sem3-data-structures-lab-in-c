//Searching and Sorting techniques

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int getFirstOccur (int[], int, int);
int getLastOccur (int[], int, int);
void printArray (int[], int);
int findMinLoc (int[], int, int);
void selectionSort (int[], int);
int countOnes (int[], int);

int main() {
	int size, arr[MAX], T;
	
	printf("\n__FIND ELEMENT IN ARRAY__\n");
	
	printf("Enter size of array: ");
	scanf("%d",&size);
	
	printf("Enter array elements: ");
	for (int i=0; i<size; i++)
		scanf("%d",&arr[i]);
		
	printf("\nEnter no. of test cases: ");
	scanf("%d",&T);
	
	int target;
	while (T--) {
		printf("\nEnter element to search for: ");
		scanf("%d",&target);
		
		printf("First occurrence: %d\n",getFirstOccur(arr,size,target));
		printf("Last occurrence: %d\n",getLastOccur(arr,size,target));
		}
		
	printf("\n\n__FIND NUMBER OF 1's IN A SORTED BINARY ARRAY__\n");
		
	printf("\nEnter no. of test cases: ");
	scanf("%d",&T);
	
	while (T--) {
		printf("\nEnter size of array: ");
		scanf("%d",&size);
		
		printf("Enter array elements (only 0 or 1 accepted): ");
		for (int i=0; i<size; i++) {
			int check;
			scanf("%d",&check);
			if (!(check==0 || check==1) || (check<arr[i-1]))
				i=-1;
			else
				arr[i] = check;
			if (i==-1) {		
				printf("Invalid entry! Enter array again.\n");
				}
			}
		
		printf("\nNumber of 1's in array: %d\n",countOnes(arr,size));
		}
	
	printf("\n\n__SELECTION SORT__\n");
		
	printf("\nEnter no. of test cases: ");
	scanf("%d",&T);
	
	while (T--) {
		printf("\nEnter size of array: ");
		scanf("%d",&size);
		
		printf("Enter array elements: ");
		for (int i=0; i<size; i++)
			scanf("%d",&arr[i]);
		
		printf("\nOriginal array: ");
		printArray(arr,size);
		
		selectionSort(arr,size);
		
		printf("\nFinal array: ");
		printArray(arr,size);
		}

	return 0;
	}
	
int getFirstOccur (int a[], int size, int target) {
	int low=0, high=size-1, mid;
	while (low <= high) {
		mid = (low+high)/2;
		if (a[mid] == target && (mid==0 || a[mid-1]<target))
			return mid;
		else if (a[mid] < target)
			low = mid+1;
		else
			high = mid-1;
		}
	return -1;
	}

int getLastOccur (int a[], int size, int target) {
	int low=0, high=size-1, mid;
	while (low <= high) {
		mid = low+(high-low)/2;
		if (a[mid] == target && (mid==size-1 || a[mid+1]>target))
			return mid;
		else if (a[mid] > target)
			high = mid-1;
		else
			low = mid+1;
		}
	return -1;
	}
	
int countOnes (int a[], int size) {
  	if (a[size-1]==0)
		return 0;
	else if (a[0]==1)
		return size;
	int pos = getFirstOccur(a,size,1);
	if (pos==-1)
		return 0;
	else
		return size-pos;
	}
	
/*
int countOnes (int a[], int size) {
	if (a[size-1]==0)
		return 0;
	else if (a[0]==1)
		return size;
	else {
		int pos = -1, target =1;		
		int low=0, high=size-1, mid;
		while (low <= high) {
			mid = low+(high-low)/2;
			if (a[mid] == target && (mid==0 || a[mid-1]<target))
				pos = mid;
			else if (a[mid] < target)
				low = mid+1;
			else
				high = mid-1;
			}
		if (pos==-1)
				return 0;
		else
			return size-pos;
		}
	return -1;
	}*/

int findMinLoc (int a[], int k, int size) { 
	int j, pos;
	pos= k; 
	for (j=k+1; j<size; j++)
		if (a[j] < a[pos])
			pos= j;
	return pos;
	}

void selectionSort (int a[], int size) {  
	int k, m, temp;
	for (k=0; k<size-1; k++) {
		m = findMinLoc(a, k, size);
		temp = a[k];
		a[k] = a[m];
		a[m] = temp;
		printArray(a,size);
		}
	}
	
void printArray (int a[], int size) {
	for (int i=0; i<size; i++)
		printf("%d ",a[i]);
	printf("\n");
	}
