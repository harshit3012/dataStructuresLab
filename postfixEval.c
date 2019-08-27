#include<conio.h>
#include<string.h>
char opd[100];
opd[0]='#';
int z=-1;

void pfeval();
void push(char num);
int pop();
bool isoperator(char x);

int main(){
	char input[];
	printf("Enter the postfix expression -\n");
	gets(input);
	pfeval(input);
	return 1;
}



void pfeval(char *inp[]){
	len=strlen(*inp);
	char outp[100];
	int i;
	for(i = 1 ; i <= len ; i++){
		if(isoperator(*inp[i])){
			push(*inp[i]);
			
			
void push(char num){
	opd[++z]=num;
}

int pop(){
	return opd[z--];
}

bool isoperator(char x){
	if((x=='+')	|| (x=='-') || (x=='*') || (x=='/') || (x=='^')){
		return true;
	else
		return false;
	}
}
