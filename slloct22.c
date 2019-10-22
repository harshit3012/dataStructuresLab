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

NODE sort(NODE head){
	NODE p = head;
	if(head == NULL){
		printf("Empty List!!\n");
		return NULL;
	}
	if(head->next == NULL){
		return head;
	}
	int temp;
	NODE last = NULL;
	while(last != head){
		while(p->next != last){
			if(p->next->data > p->data){
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
			}
			p = p->next;
		}
		last = p;
		p = head;
	}
	return head;
}
NODE merge(NODE head1, NODE head2){
	if(head1 == NULL){
		printf("List1 is empty!\n");
		return head2;
	}
	if(head2 == NULL){
		printf("List2 is empty!\n");
		return head1;
	}
	NODE x = head1;
	NODE y = head2;
	NODE head3 = NULL;		//For loop
	NODE p = head3;			//To store temporarily for return
	while((x != NULL) && (y != NULL)){
		head3 == getnode();
		if(x->data < y->data){
			head3->data = x->data;
			head3->next == getnode();
			head3 = head3->next;
			x = x->next;
			continue;
		}
		else if(x->data > y->data){
			head3->data = y->data;
			head3->next == getnode();
			head3 = head3->next;
			y = y->next;
			continue;
		}
		else{
			head3->data = x->data;
			x = x->next;
			head3->next = getnode();
			head3 = head3->next;
			continue;
		}
	}
	while(x != NULL){
		head3->data = x->data;
		head3->next == getnode();
		head3 = head3->next;
		x = x->next;
	}
	while(y != NULL){
		head3->data = y->data;
		head3->next == getnode();
		head3 = head3->next;
		y = y->next;
	}
	return head3;
}
NODE reverse(NODE head){
	if(head == NULL){
		printf("Empty List!\n");
		return head;
	}
	if(head->next == NULL){
		return head;
	}
	NODE last = NULL;
	NODE rev = getnode();
	NODE q = rev;				//To temporarily store rev head
	NODE p = head;
	while(last != head){
		while(p->next != last){
			p = p->next;
		}
		last = p;
		rev->data = last->data;
		rev->next = getnode();
		rev = rev->next;
		p = head;
	}
	return q;
}
NODE concatenate(NODE head1, NODE head2, int ch){
	
	NODE p = head1;
	NODE q = head2;
	if(ch == 1){
		while
	}
	if(ch == 2){
	}
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
int main(){
	NODE head1 = NULL;
	NODE head2 = NULL;
	NODE head3 = NULL;
	int choice;
	printf("Operations -\n1. Insert element to List 1 (From front)\n2. Insert element to List 2 (From front)\n3. Sort List 1\n4. Sort List 2\n5. Reverse List 1\n6. Reverse List 2\n7. Merge the two lists\n8. Display lists\n9. Exit\n");
	do{
		printf("Enter operation number : ");
		scanf("%d", &choice);
		switch(choice){
			case 1: head1 = insert_front(head1);
					break;
			case 2: head2 = insert_front(head2);
					break;
			case 3: head1 = sort(head1);
					break;
			case 4: head2 = sort(head2);
					break;
			case 5: head1 = reverse(head1);
					break;
			case 6: head2 = reverse(head2);
					break;
			case 7: head1 = sort(head1);
					head2 = sort(head2);
					head3 = merge(head1, head2);
					break;
			case 8: printf("List 1 : ");
					display(head1);
					printf("List 2 : ");
					display(head2);
					printf("List 3 : ");
					display(head3);
					break;
			case 9: return 0;
		}
	}while(choice != 9);
	return 0;
}
