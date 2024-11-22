//Queue ADT structure using circluar array

struct Queue {
	int front;
	int rear;
	int capacity;
	int *array;
	};

typedef struct Queue* queue_ptr;

queue_ptr createQueue(int);
void enqueue(queue_ptr,int);
int dequeue(queue_ptr);
int isFull(queue_ptr);
int isEmpty(queue_ptr);
int getRear(queue_ptr);
int getFront(queue_ptr);

queue_ptr createQueue (int size) {
	queue_ptr queue = (queue_ptr) malloc(sizeof(struct Queue));
	queue->capacity = size+1;
	queue->front = -1;
	queue->rear = -1;
	queue->array = (int*) malloc(sizeof(int) * queue->capacity);
	return queue;
	}

void enqueue (queue_ptr queue, int item) {
	int size = queue->capacity;
	/*if (isFull(queue))
		return; //queue full*/
	if (isEmpty(queue)) {
		queue->front = 0;
		queue->rear = 0;
		queue->array[queue->rear++] = item;
		return;
		}
	if (queue->rear == size-1 && queue->front != 0) {
		queue->array[queue->rear] = item;
		queue->rear = 0;
		return;
		}
	queue->array[queue->rear++] = item;
	}
	
int dequeue (queue_ptr queue) {
	if (isEmpty(queue))
		return -1; //queue empty
	int item = queue->array[queue->front];
	if (queue->front == (queue->rear-1)%(queue->capacity)) {
		queue->front = -1;
		queue->rear = -1;
		}
	else if (queue->front == (queue->capacity)-1)
		queue->front = 0;
	else
		queue->front++;
	return item;
	}

int isFull (queue_ptr queue) {
	int size = queue->capacity;
	return (queue->front == 0 && queue->rear == size-1) || (queue->rear == (queue->front-1)); //% needed?
	}
	
int isEmpty (queue_ptr queue) {
	return queue->front == -1;
	}
	
int getRear (queue_ptr queue) {
	return queue->array[queue->rear];
	}
	
int getFront (queue_ptr queue) {
	return queue->array[queue->front];
	}

