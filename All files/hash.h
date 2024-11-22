//Hash table ADT Structure
#define MAX_CAP 20
#include "hashNode.h"

struct HashTable {
	hnode* arr;
	unsigned capacity;
	int size;
	};
typedef struct HashTable* htable;

htable createTable (unsigned capacity);
int hashFunction (htable h, int key);
htable insertValue (htable h, int key, int value);
int deleteValue (htable h, int key);
int search (htable h, int key);

htable createTable (unsigned capacity) {
	htable newTable = (htable) malloc (sizeof(struct HashNode));
	newTable->size = 0;
	newTable->capacity = capacity;
	newTable->arr = (hnode*) malloc (sizeof(hnode)*capacity);
	for (int i=0; i<capacity; i++) {
		newTable->arr[i] = NULL;
		}
	return newTable;
	}

int hashFunction (htable h, int key) {
	return key%(h->capacity);
	}
	
htable insertValue (htable h, int key, int value) {
	if (search(h,key)!=-1)
		return insertValue(h,key+1,value);

	hnode newNode = (hnode) malloc (sizeof(struct HashNode));
	newNode->key = key;
	newNode->value = value;
	
	//Hash function to find index 
	int hashIndex = hashFunction(h,key);
	
	while(h->arr[hashIndex] != NULL && h->arr[hashIndex]->key != key && h->arr[hashIndex]->key != -1) {
		hashIndex++;
		hashIndex %= h->capacity;
		}
	
	if (h->arr[hashIndex] == NULL)
		h->size++;
	h->arr[hashIndex] = newNode;
	
	return h;
	}

int deleteValue (htable h, int key) {
	hnode mark = (hnode) malloc (sizeof(struct HashNode));
	mark->key = -1;
	mark->value = -1;
	
	int hashIndex = hashFunction(h,key);
	while (h->arr[hashIndex] != NULL) {
		if(h->arr[hashIndex]->key == key) {
			h->arr[hashIndex] = mark;
			h->size--;
			return 1;
			}
		hashIndex++;
		hashIndex %= h->capacity;
		}
	return -1;
	}

int search (htable h, int key) {
	int hashIndex = hashFunction(h,key);
	int counter = 0;
	while (h->arr[hashIndex] != NULL) {
		counter = 0;
		if (counter++ > h->capacity)
			break;
		if (h->arr[hashIndex]->key == key)
			return h->arr[hashIndex]->value;
		
		hashIndex++;
		hashIndex %= h->capacity;
		}
	return -1;
	}
