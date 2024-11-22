//Stack of characters ADT structure using arrays

#define NUL '\0'

struct Stack {
	int top;
	unsigned capacity;
	char* array;
	};
	
typedef struct Stack* stack_ptr;

stack_ptr createStack (unsigned);
int isFull (stack_ptr);
int isEmpty (stack_ptr);
void push (stack_ptr,char);
char pop (stack_ptr);
char getTop (stack_ptr);
	
stack_ptr createStack (unsigned capacity) {
	stack_ptr stack = (stack_ptr) malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (char*) malloc(stack->capacity * sizeof(char));
	return stack;
	}
	
int isFull (stack_ptr stack) {
	//when top equals last index
	return (stack->top == (stack->capacity - 1));
	}
	
int isEmpty (stack_ptr stack) {
	//when top equals -1
	return (stack->top == -1);
	}
	
void push (stack_ptr stack, char item) {
	//if stack full
	if (isFull(stack))
		return; //memory error, validate
	//after adding item, top increased by 1
	stack->array[++stack->top] = item;
	}
	
char pop (stack_ptr stack) {
	if (isEmpty(stack))
		return NUL;
	//returning top item and decreasing top by 1
	return stack->array[stack->top--];
	}
	
char getTop (stack_ptr stack) {
	if (isEmpty(stack))
		return NUL;
	//returning top item
	return stack->array[stack->top];
	}

