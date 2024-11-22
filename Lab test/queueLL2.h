//Queue ADT structure using linked list

//#include "ll.h"

struct QueueNode {
	int data;
	struct QueueNode* next;
	struct QueueNode* front, rear;
	};

typedef struct QueueNode* queueNode;

queueNode createQueue(int);
queueNode enqueue(queueNode,int);
int dequeue(queueNode);
int isEmpty(queueNode);
int getRear(queueNode);
int getFront(queueNode);


queueNode enqueue (queueNode qNode, int item) {
	//enter data into new node
	queueNode newNode = (queueNode) malloc(sizeof(struct QueueNode));
	if (!newNode)
		return NULL; //memory error
	newNode->data = item;
	newNode->next = NULL;
	//if empty list, make new node the head
	if (!qNode) {
		qNode = newNode;
		return qNode;
		}
	//find last node and add new node to end of linked list
	queueNode temp = qNode;
	while (temp->next) {
		temp = temp->next;
		}
	temp->next = newNode;

	return qNode;
	}

int dequeue (queueNode qNode) {
	queueNode temp = qNode;
	//if empty list
	if (!qNode)
		return -1;
	//store data of first node temporarily
	int item = temp->data;
	//shift head to second node and delete first node
	qNode = qNode->next;
	free(temp);
	//return deleted data
	return item;
	}


int getRear (queueNode qNode) {
	return getData(qNode->rear->data);
	}

int getFront (queueNode qNode) {
	return getData(qNode->front->data);
	}

int underflow (queueNode qNode) {
	if (!qNode)
		return 1;
	else
		return 0;
	}
