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
	if(head == NULL){
		printf("Empty List!!\n");
		return NULL;
	}
	if(head->next == NULL){
		return head;
	}
    NODE p = head;
	int temp;
	NODE last = NULL;
	while(last != head){
		while(p->next != last){
			if(p->next->data < p->data){
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
	NODE head3 = getnode();                //For loop
	NODE p = head3;                        //To store temporarily for return
	while((x != NULL) && (y != NULL)){
		if(x->data < y->data){
			p->data = x->data;
			x = x->next;
            if (x != NULL){
                p->next = getnode();
                p = p->next;
            }
			continue;
		}
		else if(x->data > y->data){
			p->data = y->data;
			y = y->next;
            if (x != NULL){
                p->next = getnode();
                p = p->next;
            }
			continue;
		}
		else{
			p->data = x->data;
            p->next = getnode();
            p = p->next;
            p->data = y->data;
			x = x->next;
            y = y->next;
            if((x != NULL) && (y != NULL)){     //Solves the last element is zero issue
                p->next = getnode();
                p = p->next;
            }
			continue;
		}
	}
    /*
    if((x == NULL) && (y == NULL)){     //Solves the Last element not appending issue
        return head3;
    }
    p->next = getnode();
    p = p->next;
    */
	while(x != NULL){
        p->next = getnode();
        p = p->next;
		p->data = x->data;
		x = x->next;
        /*
        if(x != NULL){                  //Solves the last element is zero issue
            p->next = getnode();
            p = p->next;
        }
        */
	}
	while(y != NULL){
        p->next = getnode();
        p = p->next;
		p->data = y->data;
		y = y->next;
        /*
        if(y != NULL){                  //Solves the Last element is zero issue
            p->next = getnode();
            p = p->next;
        }
        */
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
        if(last != head){
		    rev->next = getnode();
		    rev = rev->next;
        }
        p = head;
	}
	return q;
}
NODE concatenate(NODE head1, NODE head2, int ch){
	if(head1 == NULL){
		return head2;
	}
	if(head2 == NULL){
		return head1;
	}
	NODE p = head1;
	NODE q = head2;
	if(ch == 1){
		while(p->next != NULL){
			p = p->next;
		}
		while(q != NULL){
			p->next = getnode();
			p = p->next;
			p->data = q->data;
			q = q->next;
		}
		return head1;
	}
	if(ch == 2){
		while(q->next != NULL){
			q = q->next;
		}
		while(p != NULL){
			q->next = getnode();
			q = q->next;
			q->data = p->data;
			p = p->next;
		}
		return head2;
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
	printf("Operations -\n1. Insert element to List 1 (From front)\n2. Insert element to List 2 (From front)\n3. Sort List 1\n4. Sort List 2\n5. Reverse List 1\n6. Reverse List 2\n7. Merge the two lists\n8. Concatenate list 2 to list 1\n9. Concatenate list 1 to list 2\n10. Display lists\n11. Exit\n");
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
			case 8: head1 = concatenate(head1, head2, 1);
					break;
			case 9: head2 = concatenate(head1, head2, 2);
					break;
			case 10:printf("List 1 : ");
					display(head1);
					printf("List 2 : ");
					display(head2);
					printf("List 3 : ");
					display(head3);
					break;
			case 11: return 0;
		}
	}while(choice != 11);
	return 0;
}
