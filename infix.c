#include<stdio.h>
#include<string.h>
int F(char sym){
	switch(sym){
		case '+':
		case '-':return 2;
		case '*':
		case '/':return 4;
		case '^':
		case '$':return 5;
		case '(':return 0;
		case '#':return -1;
		default:return 8;
	}
}
int G(char sym){
	switch(sym){
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 3;
		case '^':
		case '$':return 6;
		case '(':return 9;
		case ')':return 0;
		default:return 7;
	}
}
void inPo(char infix[], char postfix[]){
	int top, i, j;
	char s[30], sym;
	top=-1;
	s[++top]='#';
	j=0;
	for(i=0 ; i<strlen(infix) ; i++){
		sym=infix[i];
		while(F(s[top])>G(sym)){
			postfix[j]=s[top--];
			j++;
		}
		if(F(s[top])!=G(sym))
			s[++top]=sym;
		else
			top--;
	}
	while(s[top]!='#'){
		postfix[j++]=s[top--];
	}
	postfix[j]='\0';
}
int main(){
	char infix[20];
	char postfix[20];
	int con;
	do{
		printf("Enter the valid infix expression\n");
		scanf("%s", infix);
		inPo(infix, postfix);
		printf("The postfix exp is - ");
		printf("%s\nDo you want to continue?(1 for yes, 0 for no)",postfix);
		scanf("%d",&con);
	}while(con==1);	
	return 0;
}
			
