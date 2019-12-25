#include<stdio.h>
#include<stdlib.h>

struct node{
	int coeff;
	int pow;
	struct node *next;
};
typedef struct node *NODE;
NODE getnode(){
	NODE p = (NODE)malloc(sizeof(struct node));
	if(!p)	exit(0);
	return p;
}
NODE insert(NODE head){
	NODE p = getnode();
	printf("Enter the Coefficient and Power : ");
	scanf("%d %d", &p->coeff, &p->pow);
	if(!head)	return p;		//when head is null
	NODE a = head;
	while(a->next)	a = a->next;	//Traverse to last node
	a->next = p;
	return head;
}
NODE add(NODE poly1, NODE poly2){
	if(!poly1)	return poly2;		//if poly1 is empty, result is poly2
	if(!poly2)	return poly1;		//if poly2 is empty, result is poly1
	NODE a = poly1;					//Nodes a and b used for traversing
	NODE b = poly2;
	NODE res = getnode();			//Node res is used for traversing the result linked list
	NODE temp = res;				//Temporary saving the head of result, and used in return statement
	while(a && b){					//While both a and b arent empty
		if(a->pow > b->pow){
			res->pow = a->pow;
			res->coeff = a->coeff;
			a = a->next;
		}
		else if(a->pow < b->pow){
			res->pow = b->pow;
			res->coeff = b->coeff;
			b = b->next;
		}
		else{
			res->pow = a->pow;
			res->coeff = a->coeff + b->coeff;
			a = a->next;
			b = b->next;
		}
		if(a && b){					//We donot want an extra node in the end, hence this condition
			res->next = getnode();
			res = res->next;
		}
	}
	//At this stage either one of the node a or b, or both are null
	//so the remaining nodes of the other node have to be appended
	while(a){
		res->next = getnode();
		res = res->next;
		res->pow = a->pow;
		res->coeff = a->coeff;
		a = a->next;
	}
	while(b){
		res->next = getnode();
		res = res->next;
		res->pow = b->pow;
		res->coeff = b->coeff;
		b = b->next;
	}
	free(a);
	free(b);
	return temp;
}
void display(NODE head){
	if(!head){
		printf("Empty!\n");
		return;
	}
	NODE p = head;
	while(p){
		printf("%dx^%d ", p->coeff, p->pow);
		p = p->next;
	}
	printf("\n");
	free(p);
	return;
}

void main(){
	int choice, pow, coeff;
	NODE head1, head2, res;
	head1 = NULL;			//Initializing
	head2 = NULL;			//Initializing
	res = NULL;				//Initializing
	printf("1. Insert to polynomial 1\n2. Insert to polynomial 2\n3. Display all poly\n4. Add poly1 and poly2\n5. Exit\n");
	do{
		printf(">>> ");
		scanf("%d", &choice);
		switch(choice){
			case 1: head1 = insert(head1);
					break;
			case 2: head2 = insert(head2);
					break;
			case 3: printf("Poly1 : ");
					display(head1);
					printf("Poly2 : ");
					display(head2);
					printf("Result: ");
					display(res);
					break;
			case 4: res = add(head1, head2);
					break;
			case 5: return;
		}
	}while(choice!=5);
	return;
}
