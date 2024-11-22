//expression helper operations

int isOperand(char);
int isOperator(char);
int precedence(char);
int checkParantheses(char[]);
int isMatch(char,char);
int validateExprn(char[]);

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
                                if (!isMatch(temp, exp[i]))
                                       return -3;
                        	  }
                        }
        	}
        if (stack->top==-1) //if stack empty
                return 1;
        else 
                return -2;
	}

//function to check if a character is an operand
int isOperand (char ch) {
	return isalnum(ch);
	}
	
//function to check if a character is a valid operator
int isOperator (char ch) {
	return ( ch=='^' || ch=='/' || ch=='*' || ch=='%' || ch=='+' || ch=='-' );
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
		default: return -1;
		}
	}
	
//function to check if opening and closing parantheses match
int isMatch (char a,char b) {
        if(a=='[' && b==']')
                return 1;
        if(a=='{' && b=='}')
                return 1;
        if(a=='(' && b==')')
                return 1;
        return 0;
	}
	
//function to validate expression
int validateExprn (char exp[]) {
	if (checkParantheses(exp) != 1)
		return -2;
	if (exp[0]!='(' && exp[0]!='[' && exp[0]!='{')
		return -3;
	for (int i=0; exp[i]; i++) {
		if (isOperator(exp[i])) {
				char left = exp[i-1], right = exp[i+1];
				if ((left == '(' || left == '[' || left == '{') || (right == ')' || right == ']' || right == '}'))
					return -4;
				}
		}
	return 1;
	}

