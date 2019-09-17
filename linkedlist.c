#include<stdio.h>
#include<stdlib.h>
struct node_struct{
	int data;
	struct node_struct *next;
};
typedef struct node_struct NODE;
NODE get_node();
NODE insert_pos(NODE head, int pos, int item);
void display(NODE head);
NODE insert_front(int item, NODE head);
void insert_end(int item, NODE head);
NODE get_node(){
	NODE p = (NODE)malloc(sizeof(struct node_struct));
	if(p != NULL)
		return p;
	else
		printf("Struct not allocated");
}
NODE insert_pos(NODE head, int pos, int item){
	NODE curr, p, new;
	NODE prev = NULL;
	int count = 1;
	p = get_node();
	p.data = item;
	p.next = NULL;
	if(head == NULL){
		if(pos == 1)
			return p;
		printf("Invalid position\n");
	}
	if(pos == 1){
		p.next = head;
		head = p;
		return head;
	}
	else{
		curr = head;
		count = 1;
		while(curr != NULL && count != pos){
			prev = curr;
			curr = curr.next;
			count++;
		}
		if(count == pos){
			prev.next = p;
			p.next = curr;
			return head;
		}
		else{
			printf("Invalid position\n");
			return head;
		}
	}
}
void display(NODE head){
	NODE p;
	if(head == NULL){
		printf("\nLinked list is empty");
		exit(0);
	}
	else
		p = head;
	while(p != NULL){
		printf("%d", p->data);
		p = p.data;
	}
}
NODE insert_front(int item, NODE head){
	NODE p = get_node();
	p.data = item;
	p.next = head;
	head = p;
	return head;
}
void insert_end(int item, NODE head){
	NODE p, q;
	q = get_node();
	q.data = item;
	p = head;
	while(p.next != NULL){
		p = p.next;
	}
	p.next = q;
	q.next = NULL;
}
void main(){
	NODE head = NULL;
	int cont;
	do{
		char op;
		printf("\nChoose operation -\n1. Insert at front\n2. Insert at a position\n3. Insert at end\n4. Display\n");
		scanf("%c", &op);
		switch(op){
			case '1' :{
				printf("\nEnter the value to be stored in first - ");
				int val;
				scanf("%d", &val);
				head = insert_front(val, head);
				break;
			}
			case '2' :{
				printf("\nEnter the position and value respectively -");
				int val, pos;
				scanf("%d", &val);
				scanf("%d", &pos);
				head = insert_pos(head, pos, val);
				break;
			}
			case '3' :{
				printf("\nEnter the value - ");
				int val;
				scanf("%d", &val);
				break;
			}
			case '4' :{
				display(head);
				break;
			}
		}
		printf("Do you want to continue?\n(1 for yes) ");
		scanf("%d", &cont);
	}while(cont = 1);
}
