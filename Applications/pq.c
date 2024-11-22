//Priority queue - Application of Binary Heap

#include <stdio.h>
#include <stdlib.h>
#include "binHeap.h"

void display (minHeap heap) {
	for (int i=0; i<=heap->size; i++)
		printf("%.1f ",heap->arr[i]);
	printf("\n");
	}

int main() {
	int nFam;
	printf("Number of families: ");
	scanf("%d",&nFam);
	minHeap incomes = NULL;
	incomes = buildHeap(nFam);
	
	float value;
	printf("Incomes in K: ");
	for (int i=0; i<nFam; i++) {
		scanf("%f",&value);
		incomes = insert(incomes,value);
		}
		
	float limit;
	printf("BPL limit: ");
	scanf("%f",&limit);
	
	printf("\nRemoved incomes: ");
	for (int i=0; incomes->arr[0]<=4 ; i++) {
		float del = deleteMin(incomes);
		printf("%.1f ",del);
		}
	printf("\n");
	
	return 0;
	}
