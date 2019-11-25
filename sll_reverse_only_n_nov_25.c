#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node *NODE;
NODE getnode(){
	NODE p = (NODE)malloc(sizeof(struct node));
	if(p != NULL){
		return p;
	}
	printf("Memory not Allocated!!\n");
	exit(0);
}
NODE insert_front(NODE head){
	int ele;
	printf("Enter data to insert : ");
	NODE p = getnode();
	scanf("%d", &ele);
	p->data = ele;
	p->next = head;
	return p;
}
void display(NODE head){
	NODE p;
	if(head == NULL){
		printf("List is empty\n");
		return;
	}
	p = head;
	printf("\t");
	while(p != NULL){
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
}
NODE reverse_n(NODE head, int n){
	if(head == NULL){
		printf("Empty!");
		return NULL;
	}
	int count = 0;
	NODE p = head;
	while(p != NULL){		//to count number of nodes
		p = p->next;
		count++;
	}
	if(n > count){
		printf("Not Possible!\n");
		return head;
	}
	int i;
	p = head;
	for(i = 0; i < (n) ; i++){	//To go to one node ahead of the nth node
		p = p->next;
	}
	NODE last = p;
	NODE temp_last = p;		//Used to store beginning node of the remaining elements
	NODE rev = getnode();
	NODE q = rev;			//Used to store the return head of rev list
	p = head;
	while(head != last){
		while(p->next != last){		//Traverse to the last but one
			p = p->next;
		}
		last = p;			//Update last
		rev->data = last->data;		//Append the elements
		if(last != head){		//when while loop is done, no new should be created
			rev->next = getnode();
			rev = rev->next;
		}
		p = head;
	}

	/*
	rev->next = getnode();		//To append the first element
	rev = rev->next;
	rev->data = head->data;
	*/
	
	while(temp_last != NULL){		//To Append the remaining elements
		rev->next = getnode();
		rev = rev->next;
		rev->data = temp_last->data;
		temp_last = temp_last->next;
	}
	return q;
}
int main(){
	NODE head1 = NULL;
	int choice, n;
	printf("Operations -\n1. Insert element to List (From front)\n2. Reverse first n nodes of list 1\n3. Display lists\n4. Exit\n");
	do{
		printf("Enter operation number : ");
		scanf("%d", &choice);
		switch(choice){
			case 1: head1 = insert_front(head1);
				break;
			case 2: printf("Enter n : ");
				scanf("%d", &n);
				head1 = reverse_n(head1, n);
				break;
			case 3: printf("List is : ");
				display(head1);
				break;
			case 4: return 0;
		}
	}while(choice != 4);
	return 0;
}
