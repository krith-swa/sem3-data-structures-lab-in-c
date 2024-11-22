//implementation of binary tree ADT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "stack.h"
#include "intStack.h"
#include "exprn.h"
#include "binTree.h"

char* InfixToPostfix(char[]);
void toIntPostfix (char[],stack_ptr,IntStack_ptr);
ptnodeInt constructIntTree (char[]);
void levelorderInt (ptnodeInt);
void postorderInt(ptnodeInt);
int evalExprn(ptnodeInt);
void validate(int,char[]);

int main() {
	char exp[50], pfExp[50];
	printf("Enter algebraic expression: ");
  	scanf("%s", exp);
  	
  	int valid = validateExprn(exp);
  	validate(valid,exp);
  	
  	if (valid == 1) {
	  	strcpy(pfExp, InfixToPostfix(exp));
	  	printf("Postfix Expression: %s\n", pfExp);
	  	
	  	ptnode exprTree = construct(pfExp);
	  	printf("Represented postfix expression as binary tree!\n");
	  	
	  	printf("\nInOrder: ");
	  	inorder(exprTree);
	  	
	  	printf("\nPostOrder: ");
	  	postorder(exprTree);
	  	
	  	printf("\nPreOrder: ");
	  	preorder(exprTree);
	  	
	  	printf("\nLevelOrder:\n");
	  	levelorder(exprTree);
	  	}
  	
  	printf("\nEnter arithmetic expression: ");
  	scanf("%s",exp);
  	
  	valid = validateExprn(exp);
  	validate(valid,exp);
  	
  	if (valid==1) {
	  	ptnodeInt tree = constructIntTree(exp);
		
		printf("\nLevelOrder:\n");
	  	levelorderInt(tree);		
		
	  	printf("\nPostOrder: ");
	  	postorderInt(tree);

	  	//converting expression to postfix and constructing integer binary tree for evaluation
	  	int result = evalExprn(tree);
	  	printf("\nExpression evaluated!\n");
	  	printf("Result: %d\n",result);
	  	}
  	
	return 0;
	}

//function to convert infix expression to postfix
char* InfixToPostfix (char exp[]) {
	stack_ptr opStack = createStack(strlen(exp));
	stack_ptr exprStack = createStack(strlen(exp));
	char* postExp = (char*) malloc (sizeof(char) * (strlen(exp)+10));
	
	if ( !((checkParantheses(exp) != 1) || (exp[0]!='(' && exp[0]!='[' && exp[0]!='{')) ) {
		for (int i=0; exp[i]; i++) {
			if (isOperand(exp[i]))
				push(exprStack,exp[i]);
			else if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
				push(opStack,exp[i]); 
			else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
				while ( !isEmpty(opStack) && getTop(opStack)!='(' )
					push(exprStack,pop(opStack));
				pop(opStack);
				}
			else if (isOperator(exp[i])) {
				char left = exp[i-1], right = exp[i+1];
				if ((left == '(' || left == '[' || left == '{') || (right == ')' || right == ']' || right == '}'))
					return (postExp);
				else {
					while ( !isEmpty(opStack) && precedence(exp[i])<=precedence(getTop(opStack)) )
						push(exprStack,pop(opStack));
					push(opStack,exp[i]);
					}
				}
			else
				return (postExp);
			}
		
		while ( !isEmpty(opStack) )
			push(exprStack,pop(opStack));
		
		//exprStack now contains reverse of postFix expression
		stack_ptr inputStack = createStack(strlen(exp));
		while ( !(isEmpty(exprStack)) )
			push(inputStack,pop(exprStack));
		
		int k=-1;
		while ( !(isEmpty(inputStack)) ) {
			postExp[++k] = pop(inputStack);
			}
		postExp[++k] = '\0';
		}
	return (postExp);
	}

//function to convert arithmetic expression to postfix
void toIntPostfix (char exp[], stack_ptr inputStack, IntStack_ptr IntStack) {
	stack_ptr opStack = createStack(strlen(exp));
	stack_ptr expStack = createStack(strlen(exp));
	IntStack_ptr integers = createIntStack(strlen(exp));
	char fill; int skip=0;
	
	if ( !((checkParantheses(exp) != 1) || (exp[0]!='(' && exp[0]!='[' && exp[0]!='{')) ) {
		for (int i=0; exp[i]; i++) {
			if (isOperand(exp[i])) {
				int j, val = exp[i]-'0';
				for (j=i+1; isOperand(exp[j]); j++) {
					int val2 = exp[j]-'0';
					val = (val*10)+val2;
					}
				pushInt(integers,val);
				push(expStack,'a'+skip);
				(++skip)%26;
				i=j-1;
				}
			else if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
				push(opStack,exp[i]); 
			else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
				while ( !isEmpty(opStack) && getTop(opStack)!='(' )
					push(expStack,pop(opStack));
				pop(opStack);
				}
			else if (isOperator(exp[i])) {
				char left = exp[i-1], right = exp[i+1];
				if ((left == '(' || left == '[' || left == '{') || (right == ')' || right == ']' || right == '}'))
					return;
				else {
					while ( !isEmpty(opStack) && precedence(exp[i])<=precedence(getTop(opStack)) )
						push(expStack,pop(opStack));
					push(opStack,exp[i]);
					}
				}
			else
				return;
			}
		
		while ( !isEmpty(opStack) )
			push(expStack,pop(opStack));
			
		while ( !(isEmpty(expStack)) )
			push(inputStack,pop(expStack));
			
		while ( !(isEmptyInt(integers)) )
			pushInt(IntStack,popInt(integers));
		}
	}

//function to add arithmetic expression into binary tree
ptnodeInt constructIntTree (char exp[]) {
	int size = strlen(exp);
	stack_ptr inputStack = createStack(size);
	IntStack_ptr IntStack = createIntStack(size);
	toIntPostfix(exp,inputStack,IntStack);

	btStackInt_ptr exprStack = createBTIntStack(size);
	while (! isEmpty(inputStack) ) {
		char c = pop(inputStack);
		if (isOperand(c)) {
			int num = popInt(IntStack);
			pushBTInt(exprStack,insertNodeInt(num));
			}
		else {
			ptnodeInt head = insertNodeChar(c);
			head->right = popBTInt(exprStack);
			head->left = popBTInt(exprStack);
			pushBTInt(exprStack,head);
			}
		}
	return popBTInt(exprStack);
	}

//function to evaluate postfix expression using integer stack
int evalExprn (ptnodeInt root) {
	
	if (!root)
		return 0;
	if (!root->left && !root->right)
		return root->data;
		
	int lValue = evalExprn(root->left);
	int rValue = evalExprn(root->right);
	
	switch(root->item) {
		case '+': return lValue+rValue;
		case '-': return lValue-rValue;
		case '*': return lValue*rValue;
		case '/': return lValue/rValue;
		case '^': return pow(lValue,rValue);
		case '%': return lValue%rValue;
		case '$': return root->data;
		}
	}
	
//function to validate input expression
void validate (int result, char exp[]) {
	if (result == -2) {
		//to check if expression entered is valid or not
		int check = checkParantheses(exp);
		if (check == 1)
			printf("Parantheses are balanced. The expression is valid.\n");
		else if (check == -1)
			printf("The no. of right parentheses is more than the no. of left parentheses.\nParantheses are not balanced. The expression is invalid.\n");
		else if (check == -2)
			printf("The no. of left parentheses is more than the no. of right parentheses.\nParantheses are not balanced. The expression is invalid.\n");
		else if (check == -3)
			printf("Mismatched parentheses.\nParantheses are not balanced. The expression is invalid.\n");
		else
			printf("Invalid expression!\n");
		}
	else if (result == -3)
		printf("Expression must be enclosed in parantheses.\n");
	else if (result == -4)
		printf("Operators must be present between operands in an infix expresion.\n");
	}

//function for postorder traveresal of arithmetic expression tree
void postorderInt (ptnodeInt root) {
	if (root) {
		postorderInt(root->left);
		postorderInt(root->right);
		if ( root->item == '$' )
			printf("%d ",root->data);
		else if (isOperator(root->item))
			printf("%c ",root->item);
		}
	}

//function to print integer expression tree
void levelorderInt (ptnodeInt root) {
	btQueueInt_ptr levelQueue = createBTIntQueue(SIZE);
	ptnodeInt EOL = insertNodeChar('|');
	ptnodeInt EOB = insertNodeChar(';');
	ptnodeInt blank = insertNodeChar('_');
	int ht = heightInt(root);
	
	enqueueIntBT(levelQueue,EOL);
	int level = 1, k=0, eob=0;
	for (int i=0; i<=(ht-level); i++)
		printf("\t");
	while (root) {
		if (root!=blank && root!=EOB) {
			if ( root->item == '$' )
				printf("%d\t\t",root->data);
			else if (isOperator(root->item))
				printf("%c\t\t",root->item);
			if (root->left)
				enqueueIntBT(levelQueue,root->left);
			else
				enqueueIntBT(levelQueue,blank);
			if (root->right)
				enqueueIntBT(levelQueue,root->right);
			else
				enqueueIntBT(levelQueue,blank);
			enqueueIntBT(levelQueue,EOB);
			root = dequeueIntBT(levelQueue);
			}
			
		while (root == blank) {
			root = dequeueIntBT(levelQueue);
			printf("\t");
			k++;
			}
		while (root == EOB) {
			root = dequeueIntBT(levelQueue);
			if (root != EOL) {
				printf("  ");
				eob++;
				}
			}
		if (root == EOL) {
			root = dequeueIntBT(levelQueue);
			if (root != NULL) {
				enqueueIntBT(levelQueue,EOL);
				level++;
				printf("\n\n");
				for (int i=0; i<=(ht-level); i++)
					printf("\t");
				for (int i=0; i<k; i++)
					printf("\t");
				for (int i=0; i<eob; i++)
					printf("   ");
				}
			}
		}
	printf("\n");
	}
