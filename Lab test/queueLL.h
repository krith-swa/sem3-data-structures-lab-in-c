//Queue ADT structure using linked list

#include "ll.h"

struct QueueNode {
	pnode node;
	pnode front, rear;
	struct QueueNode* link;
	};

typedef struct QueueNode* queueNode;

queueNode createQueue(int);
queueNode enqueue(queueNode,int);
int dequeue(queueNode);
int isEmpty(queueNode);
int getRear(queueNode);
int getFront(queueNode);


queueNode enqueue (queueNode qNode, int item) {
	pnode newNode = NULL;
	newNode = insertLast(newNode,item);
	printf("in");	
	//if queue empty
	if (!qNode) {
		qNode->node = newNode;
		qNode->front = qNode->rear = newNode;	
		}	
	//enter data node into queue
	queueNode temp = qNode;
	temp->link->node = newNode;
	qNode->rear = temp->link->node;

	return qNode;
	}

int dequeue (queueNode qNode) {
	int item = deleteFirst(qNode->front);
	return item;
	}


int getRear (queueNode qNode) {
	return getData(qNode->rear);
	}

int getFront (queueNode qNode) {
	return getData(qNode->front);
	}

int underflow (queueNode qNode) {
	if (!qNode)
		return 1;
	else
		return 0;
	}
