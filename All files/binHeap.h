//Binary Heap - MinHeap - ADT Structure using arrays
#define EMPTY -1

struct Heap {
	unsigned capacity;
	int size;
	float* arr;
	};
typedef struct Heap* minHeap;

minHeap buildHeap (unsigned);
minHeap insert (minHeap,float);
float deleteMin (minHeap);
int parent (int);
int leftChild (int);
int rightChild (int);
void swap (float[],int,int);
void heapifyUp (minHeap,int);
void heapifyDown (minHeap,int);

minHeap buildHeap (unsigned capacity) {
	minHeap heap = (minHeap) malloc (sizeof(struct Heap));
	heap->capacity = capacity;
	heap->size = -1;
	heap->arr = (float*) malloc (heap->capacity * sizeof(float));
	return heap;
	}

minHeap insert (minHeap heap, float key) {
	//if heap is full
	if (heap->size!=-1 && (heap->size >= heap->capacity-1))
		return heap;
	//insert key into heap as last node
	heap->arr[++heap->size] = key;
	//ensure heap structure
	heapifyUp(heap,heap->size);
	return heap;
	}

float deleteMin (minHeap heap) {
	//if heap is empty
	if (heap->size == -1)
		return EMPTY;
	//swap root node key and last node key	
	swap(heap->arr,0,heap->size);
	//delete last node
	float temp = heap->arr[heap->size--];
	//ensure heap structure
	heapifyDown(heap,0);
	//return minimum key
	return temp;
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

void swap (float heapArr[], int pos1, int pos2) {
	float temp = heapArr[pos1];
	heapArr[pos1] = heapArr[pos2];
	heapArr[pos2] = temp;
	}

void heapifyUp (minHeap heap, int i) {	
	while (i>0 && (heap->arr[parent(i)] > heap->arr[i])) {
		//swap parent node key and current node key
		swap(heap->arr,parent(i),i);
		//update i to parent of i
		i = parent(i);
		}
	}

void heapifyDown (minHeap heap, int i) {
	int minIndex = i;
	//left child check
	int l = leftChild(i);
	if ((l <= heap->size) && (heap->arr[l] < heap->arr[minIndex]))
		minIndex = l;
	//right child check
	int r = rightChild(i);
	if ((r <= heap->size) && (heap->arr[r] < heap->arr[minIndex]))
		minIndex = r;
	//swap minimum key with current node key
	if (i!=minIndex) {
		swap(heap->arr,minIndex,i);
		heapifyDown(heap,minIndex);
		}
	}

