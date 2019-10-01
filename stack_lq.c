#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node *NODE;
NODE getnode(){
	NODE p;
	p = (NODE)malloc(sizeof(struct node));
	if (p != NULL)
		return p;
	else{
		printf("Memory not allocated!!");
		exit(0);
	}
}
NODE push(NODE top, int ele){
	NODE p;
	p = getnode();
	p->data = ele;
	p->next = top;
	top = p;
	return top;
}
NODE pop(NODE top){
	if(top == NULL){
		printf("Underflow!!\n");
		return top;
	}
	printf("Popped element is %d\n", top->data);
	top = top->next;
	return top;
}
void display(NODE top){
	NODE p;
	if(top == NULL){
		printf("Stack is empty!\n");
		return;
	}
	p = top;
	printf("\t");
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
int main(){
	NODE top = NULL;
	int choice, ele;
	do{
		printf("1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
		scanf("%d", &choice);
		switch(choice){
			case 1: printf("Enter element to Push - ");
					scanf("%d", &ele);
					top = push(top, ele);
					break;
			case 2: top = pop(top);
					break;
			case 3: printf("Elements in Queue are - \n");
					display(top);
					break;
			case 4: exit(0);
		}
	}while(choice != 4);
	return 0;
}
