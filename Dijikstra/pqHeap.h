//MinHeap as priority queue - ADT Structure using arrays - each node contains key-value pair
#define EMPTY -1

struct pqMinHeap {
	unsigned capacity;
	int size;
	int* key;
	int* value;
	};
typedef struct pqMinHeap* pqHeap;

pqHeap createPQ (unsigned);
pqHeap insertPQ (pqHeap,int,int);
int deleteMin (pqHeap);
int parent (int);
int leftChild (int);
int rightChild (int);
void swap (int[],int,int);
void heapifyUp (pqHeap,int);
void heapifyDown (pqHeap,int);
int isEmpty (pqHeap);
int isFull (pqHeap);

pqHeap createPQ (unsigned capacity) {
	pqHeap heap = (pqHeap) malloc (sizeof(struct pqMinHeap));
	heap->capacity = capacity;
	heap->size = -1;
	heap->key = (int*) malloc (heap->capacity * sizeof(int));
	heap->value = (int*) malloc (heap->capacity * sizeof(int));
	return heap;
	}

pqHeap insertPQ (pqHeap heap, int key, int value) {
	//if heap is full
	if (isFull(heap))
		return heap;
	//insert key into heap as last node
	heap->key[++heap->size] = key;
	heap->value[heap->size] = value;
	//ensure heap structure
	heapifyUp(heap,heap->size);
	return heap;
	}

int deleteMin (pqHeap heap) {
	//if heap is empty
	if (isEmpty(heap))
		return EMPTY;
	//swap root node key and last node key	
	swap(heap->key,0,heap->size);
	swap(heap->value,0,heap->size);
	//delete last node
	int temp = heap->value[heap->size--];
	//ensure heap structure
	heapifyDown(heap,0);
	//return minimum key
	return temp; //check - RETURN KEY OR VALUE??? FOR DIJKSTRA
	}

void heapifyUp (pqHeap heap, int i) {	
	while (i>0 && (heap->key[parent(i)] > heap->key[i])) {
		//swap parent node key and current node key
		swap(heap->key,parent(i),i);
		swap(heap->value,parent(i),i);
		//update i to parent of i
		i = parent(i);
		}
	}

void heapifyDown (pqHeap heap, int i) {
	int minIndex = i;
	//left child check
	int l = leftChild(i);
	if ((l <= heap->size) && (heap->key[l] < heap->key[minIndex]))
		minIndex = l;
	//right child check
	int r = rightChild(i);
	if ((r <= heap->size) && (heap->key[r] < heap->key[minIndex]))
		minIndex = r;
	//swap minimum key with current node key
	if (i!=minIndex) {
		swap(heap->key,minIndex,i);
		swap(heap->value,minIndex,i);
		heapifyDown(heap,minIndex);
		}
	}

int isEmpty (pqHeap heap) {
	return heap->size == -1;
	}
	
int isFull (pqHeap heap) {
	return (heap->size!=-1 && (heap->size >= heap->capacity-1));
	}

int parent (int i) {
	return (i-1)/2;
	}

int leftChild (int i) {
	return (2*i)+1;
	}

int rightChild (int i) {
	return (2*i)+2;
	}

void swap (int heapArr[], int pos1, int pos2) {
	int temp = heapArr[pos1];
	heapArr[pos1] = heapArr[pos2];
	heapArr[pos2] = temp;
	}
