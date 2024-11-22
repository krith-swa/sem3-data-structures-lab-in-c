//Stack of tree nodes with integer values accepted- ADT structure using arrays

struct btStackInt {
	int top;
	unsigned capacity;
	ptnodeInt *array;
	};
	
typedef struct btStackInt* btStackInt_ptr;

btStackInt_ptr createBTIntStack (unsigned);
int isBTIntFull (btStackInt_ptr);
int isBTIntEmpty (btStackInt_ptr);
void pushBTInt (btStackInt_ptr,ptnodeInt);
ptnodeInt popBTInt (btStackInt_ptr);
	
btStackInt_ptr createBTIntStack (unsigned capacity) {
	btStackInt_ptr treeStack = (btStackInt_ptr) malloc(sizeof(struct btStackInt));
	treeStack->capacity = capacity;
	treeStack->top = -1;
	treeStack->array = (ptnodeInt*) malloc(treeStack->capacity * sizeof(struct tnode));
	return treeStack;
	}
	
int isBTIntFull (btStackInt_ptr treeStack) {
	//when top equals last index
	return (treeStack->top == (treeStack->capacity - 1));
	}
	
int isBTIntEmpty (btStackInt_ptr treeStack) {
	//when top equals -1
	return (treeStack->top == -1);
	}
	
void pushBTInt (btStackInt_ptr treeStack, ptnodeInt item) {
	//if tree stack full
	if (isBTIntFull(treeStack))
		return; //memory error, validate
	//after adding item, top increased by 1
	treeStack->array[++treeStack->top] = item;
	}
	
ptnodeInt popBTInt (btStackInt_ptr treeStack) {
	if (isBTIntEmpty(treeStack))
		return NULL;
	//returning top item and decreasing top by 1
	return treeStack->array[treeStack->top--];
	}
