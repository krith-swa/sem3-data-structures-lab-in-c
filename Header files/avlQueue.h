//Queue of avl nodes - ADT structure using circular array

#define SIZE 20

struct avlQueue {
	int front;
	int rear;
	int capacity;
	AVL *array;
	};

typedef struct avlQueue* avlQueue_ptr;

avlQueue_ptr createAVLQueue(int);
void enqueueAVL(avlQueue_ptr,AVL);
AVL dequeueAVL(avlQueue_ptr);
int isFullAVL(avlQueue_ptr);
int isEmptyAVL(avlQueue_ptr);

avlQueue_ptr createAVLQueue (int size) {
	avlQueue_ptr treeQueue = (avlQueue_ptr) malloc(sizeof(struct avlQueue));
	treeQueue->capacity = size+1;
	treeQueue->front = -1;
	treeQueue->rear = -1;
	treeQueue->array = (AVL*) malloc(sizeof(struct avlQueue) * treeQueue->capacity);
	return treeQueue;
	}

void enqueueAVL (avlQueue_ptr treeQueue, AVL item) {
	int size = treeQueue->capacity;
	if (isFullAVL(treeQueue))
		return;
	if (isEmptyAVL(treeQueue)) {
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
	
AVL dequeueAVL (avlQueue_ptr treeQueue) {
	if (isEmptyAVL(treeQueue))
		return NULL; //treeQueue empty
	AVL item = treeQueue->array[treeQueue->front];
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

int isFullAVL (avlQueue_ptr treeQueue) {
	int size = treeQueue->capacity;
	return (treeQueue->front == 0 && treeQueue->rear == size-1) || (treeQueue->rear == (treeQueue->front-1));
	}
	
int isEmptyAVL (avlQueue_ptr treeQueue) {
	return treeQueue->front == -1;
	}

