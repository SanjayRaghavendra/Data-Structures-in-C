#include <stdio.h>
int eval();
int pop();
void push(int);

typedef enum{
	times,mod,plus,minus,divide,eos,operand
}precedence;

precedence getToken(char *, int *);

int stack[20],top;
char expr[20];

int main(){
	printf("enter the postfix expression\n");
	scanf("%s",expr);
	int answer = eval();
	printf("final answer is %d\n" , answer);
	return 0;
}

int eval(){
	char symbol; int n,op1,op2;
	top =-1;
	n=0;
	precedence token = getToken(&symbol, &n);
	while(token!=eos){
		if(token==operand){
			push(symbol-'0');
		}

		else{
			op2 = pop();
			op1 = pop();
		}

		switch(token){
			case plus : push(op1+op2);
						break;
			case minus: push(op1-op2);
						break;
			case times: push(op1*op2);
						break;
			case mod  : push(op1%op2);
						break;
			case divide: push(op1/op2);
						break;

		
		}
		token = getToken(&symbol, &n);
	}
	return pop();
}

int pop(){
	return stack[top--];
}

void push(int c){
	stack[++top] = c;

}

precedence getToken(char *s, int *n){
	*s = expr[(*n)++];

	switch(*s){
		case '+': return plus;
		case '-': return minus;
		case '*': return times;
		case '/': return divide;
		case '%': return mod;
		case ';': return eos;
		default : return operand;
	}
}





