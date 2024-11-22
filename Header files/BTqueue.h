//Queue of tree nodes - ADT structure using circular array

#define SIZE 20

struct btQueue {
	int front;
	int rear;
	int capacity;
	ptnode *array;
	};

typedef struct btQueue* btQueue_ptr;

btQueue_ptr createBTQueue(int);
void enqueueBT(btQueue_ptr,ptnode);
ptnode dequeueBT(btQueue_ptr);
int isFullBT(btQueue_ptr);
int isEmptyBT(btQueue_ptr);

btQueue_ptr createBTQueue (int size) {
	btQueue_ptr treeQueue = (btQueue_ptr) malloc(sizeof(struct btQueue));
	treeQueue->capacity = size+1;
	treeQueue->front = -1;
	treeQueue->rear = -1;
	treeQueue->array = (ptnode*) malloc(sizeof(struct btQueue) * treeQueue->capacity);
	return treeQueue;
	}

void enqueueBT (btQueue_ptr treeQueue, ptnode item) {
	int size = treeQueue->capacity;
	if (isFullBT(treeQueue))
		return;
	if (isEmptyBT(treeQueue)) {
		treeQueue->front = 0;
		treeQueue->rear = 0;
		treeQueue->array[treeQueue->rear++] = item;
		return;
		}
	if (treeQueue->rear == size-1 && treeQueue->front != 0) {
		treeQueue->array[treeQueue->rear] = item;
		treeQueue->rear = 0;
		return;
		}
	treeQueue->array[treeQueue->rear++] = item;
	}
	
ptnode dequeueBT (btQueue_ptr treeQueue) {
	if (isEmptyBT(treeQueue))
		return NULL; //treeQueue empty
	ptnode item = treeQueue->array[treeQueue->front];
	if (treeQueue->front == (treeQueue->rear-1)%(treeQueue->capacity)) {
		treeQueue->front = -1;
		treeQueue->rear = -1;
		}
	else if (treeQueue->front == (treeQueue->capacity)-1)
		treeQueue->front = 0;
	else
		treeQueue->front++;
	return item;
	}

int isFullBT (btQueue_ptr treeQueue) {
	int size = treeQueue->capacity;
	return (treeQueue->front == 0 && treeQueue->rear == size-1) || (treeQueue->rear == (treeQueue->front-1));
	}
	
int isEmptyBT (btQueue_ptr treeQueue) {
	return treeQueue->front == -1;
	}
