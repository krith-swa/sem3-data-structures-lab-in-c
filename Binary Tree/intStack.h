//Stack of integers ADT structure using arrays

#define EMPTY -1

struct intStack {
	int top;
	unsigned capacity;
	int* array;
	};
	
typedef struct intStack* IntStack_ptr;

IntStack_ptr createIntStack (unsigned);
int isFullInt (IntStack_ptr);
int isEmptyInt (IntStack_ptr);
void pushInt (IntStack_ptr,int);
int popInt (IntStack_ptr);
int getTopInt (IntStack_ptr);
	
IntStack_ptr createIntStack (unsigned capacity) {
	IntStack_ptr stack = (IntStack_ptr) malloc(sizeof(struct intStack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));
	return stack;
	}
	
int isFullInt (IntStack_ptr stack) {
	//when top equals last index
	return (stack->top == (stack->capacity - 1));
	}
	
int isEmptyInt (IntStack_ptr stack) {
	//when top equals -1
	return (stack->top == -1);
	}
	
void pushInt (IntStack_ptr stack, int item) {
	//if stack full
	if (isFullInt(stack))
		return; //memory error, validate
	//after adding item, top increased by 1
	stack->array[++stack->top] = item;
	}
	
int popInt (IntStack_ptr stack) {
	if (isEmptyInt(stack))
		return EMPTY;
	//returning top item and decreasing top by 1
	return stack->array[stack->top--];
	}
	
int getTopInt (IntStack_ptr stack) {
	if (isEmptyInt(stack))
		return EMPTY;
	//returning top item
	return stack->array[stack->top];
	}

