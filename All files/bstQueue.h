//Queue of bst nodes - ADT structure using circular array

#define SIZE 20

struct bstQueue {
	int front;
	int rear;
	int capacity;
	pnodeBST *array;
	};

typedef struct bstQueue* bstQueue_ptr;

bstQueue_ptr createBSTQueue(int);
void enqueueBST(bstQueue_ptr,pnodeBST);
pnodeBST dequeueBST(bstQueue_ptr);
int isFullBST(bstQueue_ptr);
int isEmptyBST(bstQueue_ptr);

bstQueue_ptr createBSTQueue (int size) {
	bstQueue_ptr treeQueue = (bstQueue_ptr) malloc(sizeof(struct bstQueue));
	treeQueue->capacity = size+1;
	treeQueue->front = -1;
	treeQueue->rear = -1;
	treeQueue->array = (pnodeBST*) malloc(sizeof(struct bstQueue) * treeQueue->capacity);
	return treeQueue;
	}

void enqueueBST (bstQueue_ptr treeQueue, pnodeBST item) {
	int size = treeQueue->capacity;
	if (isFullBST(treeQueue))
		return;
	if (isEmptyBST(treeQueue)) {
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
	
pnodeBST dequeueBST (bstQueue_ptr treeQueue) {
	if (isEmptyBST(treeQueue))
		return NULL; //treeQueue empty
	pnodeBST item = treeQueue->array[treeQueue->front];
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

int isFullBST (bstQueue_ptr treeQueue) {
	int size = treeQueue->capacity;
	return (treeQueue->front == 0 && treeQueue->rear == size-1) || (treeQueue->rear == (treeQueue->front-1));
	}
	
int isEmptyBST (bstQueue_ptr treeQueue) {
	return treeQueue->front == -1;
	}

