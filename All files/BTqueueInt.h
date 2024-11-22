//Queue of tree nodes - ADT structure using circular array

#define SIZE 20

struct btQueueInt {
	int front;
	int rear;
	int capacity;
	ptnodeInt *array;
	};

typedef struct btQueueInt* btQueueInt_ptr;

btQueueInt_ptr createBTIntQueue(int);
void enqueueIntBT(btQueueInt_ptr,ptnodeInt);
ptnodeInt dequeueIntBT(btQueueInt_ptr);
int isFullBTInt(btQueueInt_ptr);
int isEmptyBTInt(btQueueInt_ptr);

btQueueInt_ptr createBTIntQueue (int size) {
	btQueueInt_ptr treeQueue = (btQueueInt_ptr) malloc(sizeof(struct btQueueInt));
	treeQueue->capacity = size+1;
	treeQueue->front = -1;
	treeQueue->rear = -1;
	treeQueue->array = (ptnodeInt*) malloc(sizeof(struct btQueue) * treeQueue->capacity);
	return treeQueue;
	}

void enqueueIntBT (btQueueInt_ptr treeQueue, ptnodeInt item) {
	int size = treeQueue->capacity;
	if (isFullBTInt(treeQueue))
		return;
	if (isEmptyBTInt(treeQueue)) {
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
	
ptnodeInt dequeueIntBT (btQueueInt_ptr treeQueue) {
	if (isEmptyBTInt(treeQueue))
		return NULL; //treeQueue empty
	ptnodeInt item = treeQueue->array[treeQueue->front];
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

int isFullBTInt (btQueueInt_ptr treeQueue) {
	int size = treeQueue->capacity;
	return (treeQueue->front == 0 && treeQueue->rear == size-1) || (treeQueue->rear == (treeQueue->front-1));
	}
	
int isEmptyBTInt (btQueueInt_ptr treeQueue) {
	return treeQueue->front == -1;
	}

