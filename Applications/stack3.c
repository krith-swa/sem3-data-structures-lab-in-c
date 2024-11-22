//implementation of stack of charcters ADT using arrays

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "stack.h"

#define MAX 30

float toPostfix(char[]);
void evaluate();
int isOperand(char);
int precedence(char);
int checkParantheses(char[]);
int match(char,char);
int checkpt=0;

//function to convert infix expression to postfix
float toPostfix (char exp[]) {
	//declaration of operation stack
	stack_ptr opStack = createStack(strlen(exp));
	stack_ptr exprStack = createStack(strlen(exp));
	if (!opStack || !exprStack)
		return -1;
	if (checkParantheses(exp) != 1)
		return -2;
	if (exp[0]!='(' && exp[0]!='[' && exp[0]!='{')
		return -3;
		
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
		else { //operator
			char left = exp[i-1], right = exp[i+1];
			if (!isOperand(left)) {
				if (left == '(' || left == '[' || left == '{')
					return -4;
				}
			if (!isOperand(right)) {
				if (right == ')' || right == ']' || right == '}')
					return -4;
				}
			while ( !isEmpty(opStack) && precedence(exp[i])<=precedence(getTop(opStack)) )
				push(exprStack,pop(opStack));
			push(opStack,exp[i]);
			}
		}
	
	while ( !isEmpty(opStack) )
		push(exprStack,pop(opStack));
	
	//exprStack now contains reverse of postFix expression
	stack_ptr inputStack = createStack(strlen(exp));
	while ( !(isEmpty(exprStack)) ) {
		push(inputStack,pop(exprStack));
		}
	
	//stack for evaluation of postfix
	stack_ptr evalStack = createStack(strlen(exp));
	
	while ( !(isEmpty(inputStack)) ) {
		char scan = pop(inputStack);
		if (isOperand(scan)) {
			push(evalStack, scan-'0');
			}
		else {
			int val1 = pop(evalStack);
			int val2 = pop(evalStack);
			switch (scan) {
				case '+': push(evalStack, val2 + val1); break;
				case '-': push(evalStack, val2 - val1); break;
				case '*': push(evalStack, val2 * val1); break;
				case '/': push(evalStack, val2/val1); break;
				case '^': push(evalStack, pow(val2,val1)); break;
				}
			}
		}
	float result = pop(evalStack);
	checkpt=1;
        
	return result;
	}

//function to check if parantheses are balanced or not
int checkParantheses (char exp[]) {
	//declaration of stack
	stack_ptr stack = createStack(strlen(exp));
        char temp;
        for (int i=0; i<strlen(exp); i++) {
                if (exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
                        push(stack,exp[i]);
                else if (exp[i]==')' || exp[i]=='}' || exp[i]==']') {
                        if (stack->top==-1)   //if stack empty
                                return -1;
                        else {
                                temp=pop(stack);
                                if (!match(temp, exp[i]))
                                       return -3;
                        	  }
                        }
        	}
        if (stack->top==-1) //if stack empty
                return 1;
        else 
                return -2;
	}

int main() {
	//input arithmetic expression
	char exp[MAX];
        printf("Enter an arithmetic expression: ");
        scanf("%s",exp);
		
	//to convert infix expression to postfix and evaluate
	
	float result = toPostfix(exp);
	if (result == -1 && checkpt == 0)
		printf("Memory error!\n");
	else if (result == -2 && checkpt == 0) {
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
	else if (result == -3 && checkpt == 0)
		printf("Expression must be enclosed in parantheses.\n");
	else if (result == -4 && checkpt == 0)
		printf("Operators must be present between operands in an infix expresion.\n");
	else {
		printf("Result: %f\n",result);
		checkpt=0;
		}
		
	return 0;
	}
	
//function to check if a character is an operand
int isOperand (char ch) {
		return isalnum(ch);
	}
	
//function to find precedence of an operator
int precedence (char ch) {
		switch (ch) {
			case '^': 
				{ return 3; break; }
			case '/': case '*': case '%': 
				{ return 2; break; }
			case '+': case '-': 
				{ return 1; break; }
			case '(': case ')': case '[': case ']': case '{': case '}': 
				{ return 0; break; }
			default: return -1;
			}
	}
	
//function to check if opening and closing parantheses match
int match (char a,char b) {
        if(a=='[' && b==']')
                return 1;
        if(a=='{' && b=='}')
                return 1;
        if(a=='(' && b==')')
                return 1;
        return 0;
	}
