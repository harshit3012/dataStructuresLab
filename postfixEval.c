#include<stdio.h>
#include<ctype.h>
void push(int stack[], int *z, int a);
int pop(int stack[], int *z);
int res(int a, int b, char c);
int main(){
	int s[20], top = -1, i = 0, value;
	int opr1, opr2, ans, x;
	char post[100];
	printf("Enter the Postfix expression - ");
	scanf("%s", post);
	while(post[i] != '\0'){
		if(isdigit(post[i])){
			x = (int)post[i] - 48;
			push(s, &top, x);
        }
		else{
			opr2 = pop(s, &top);
			opr1 = pop(s, &top);
			value = res(opr1, opr2, post[i]);
			push(s, &top, value);
        }
		i++;
    	}
    	ans = pop(s, &top);
    	printf("Result = %d\n", ans);
    	return 1;
}
void push(int stack[], int *z, int a){
	if (*z == 19){
		printf("Stack Overflow\n");
   	}
	*z += 1;
	stack[*z] = a;
}
int pop(int stack[], int *z){
	if(*z == -1){
		printf("Stack Underflow\n");
		return 0;
    }
	return stack[(*z)--];
}
int res(int a, int b, char c){
	switch(c){
        case '+': return (a+b);
		case '-': return (a-b);
		case '*': return (a*b);
		case '/': return (a/b);
    	}
}
