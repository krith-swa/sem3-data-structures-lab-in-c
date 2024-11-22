//Stack of tree nodes - ADT structure using arrays

struct btStack {
	int top;
	unsigned capacity;
	ptnode *array;
	};
	
typedef struct btStack* btStack_ptr;

btStack_ptr createBTStack (unsigned);
int isBTFull (btStack_ptr);
int isBTEmpty (btStack_ptr);
void pushBT (btStack_ptr,ptnode);
ptnode popBT (btStack_ptr);
ptnode getTopBT (btStack_ptr);
	
btStack_ptr createBTStack (unsigned capacity) {
	btStack_ptr treeStack = (btStack_ptr) malloc(sizeof(struct btStack));
	treeStack->capacity = capacity;
	treeStack->top = -1;
	treeStack->array = (ptnode*) malloc(treeStack->capacity * sizeof(struct tnode));
	return treeStack;
	}
	
int isBTFull (btStack_ptr treeStack) {
	//when top equals last index
	return (treeStack->top == (treeStack->capacity - 1));
	}
	
int isBTEmpty (btStack_ptr treeStack) {
	//when top equals -1
	return (treeStack->top == -1);
	}
	
void pushBT (btStack_ptr treeStack, ptnode item) {
	//if tree stack full
	if (isBTFull(treeStack))
		return; //memory error, validate
	//after adding item, top increased by 1
	treeStack->array[++treeStack->top] = item;
	}
	
ptnode popBT (btStack_ptr treeStack) {
	if (isBTEmpty(treeStack))
		return NULL;
	//returning top item and decreasing top by 1
	return treeStack->array[treeStack->top--];
	}
	
ptnode getTopBT (btStack_ptr treeStack) {
	if (isBTEmpty(treeStack))
		return NULL;
	//returning top item
	return treeStack->array[treeStack->top];
	}
	
#include "BTstackInt.h"
