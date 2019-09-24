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
    if(p != NULL)
        return p;
    else{
    	printf("Memory could not be allocated");
        exit(0);
    }
}
NODE insert_beg(NODE head, int ele){
    NODE p;
    p = getnode();
    p->data = ele;
    p->next = head;
    head = p;
    return head;
}
NODE insert_end(NODE head, int ele){
    NODE p, q;
    p = getnode();
    p->data = ele;
    p->next = NULL;
    q = head;
    if(head == NULL)
     	return p;
    while(q->next != NULL){
        q = q->next;
    }
    q->next = p;
    return q;
}
NODE insert_pos(NODE head, int item, int pos){
	NODE curr, prev = NULL, newn;
	int count = 1;
	newn = getnode();
	newn->data = item;
	newn->next = NULL;
	if(head == NULL){
		if(pos == 1)
			return newn;
		else{
			printf("Invalid position\n");
			return 0;
		}
	}
	if(pos == 1){
		newn->next = head;
		head = newn;
		return head;
	}
	else{
		curr = head;
		while((curr != NULL) && (count != pos)){
			prev = curr;
			curr = curr->next;
			count++;
		}
		if(count == pos){
			prev->next = newn;
			newn->next = curr;
			return head;
		}
		else{
			printf("Invalid position\n");
			return head;
		}
	}
}
void search(NODE head, int ele){
    NODE q;
    q = head;
    int flag = 0;
    while(q != NULL){
        if(q->data == ele){
        	flag++;
            printf("Element found\n");
          	break;
      	}
    	q = q->next;
    }
    if(flag == 0)
        printf("Element not found\n");
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
int nodes(NODE head){
    NODE q = head;
    int count = 0;
    if(head = NULL)
        return 0;
    while(q != NULL){
        count++;
        q = q->next;
    }
    return count;
}
NODE delete_end(NODE head){
    NODE p = head;
    if(head->next == NULL){
    	return head;
    }
    while((p->next)->next!=NULL){
    	p = p->next;
    }
    p->next = NULL;
    return head;
}
NODE delete_front(NODE head){
	if(head == NULL){
		printf("LIST IS EMPTY");
    	return head;
    }
        //printf("Deleted element=%d\n", head->data); 
        head = head->next;
        return head;
}
int main(){
    NODE head = NULL;
    int choice, ele, n, pos, value, i=0;
	while(i != 5){
		printf("1. Insert at the Front\n2. Insert at the End\n3. Insert at a specific position\n4. Display\n5. Search an element\n6. Delete the front element\n7. Delete the last element\n8. Display number of nodes and exit\n");
		printf("Enter option\n");
		scanf("%d", &choice);
		switch(choice){
			case 1: printf("Enter element to be inserted\n");
					scanf("%d", &ele);
					head = insert_beg(head, ele);
					break;
			case 2: printf("Enter element to be inserted\n");
					scanf("%d", &ele);
					head = insert_end(head, ele);
					break;
			case 3:	printf("Enter position and value\n");
					scanf("%d%d", &pos, &value);
					head = insert_pos(head, value, pos);
					break;
			case 4:	printf("Elements in list are\n");
					display(head);
					break;
			case 5: printf("Enter the element to be searched\n");
			        scanf("%d", &ele);
			    	search(head, ele);
					break;
			case 6: head = delete_front(head);
					break;
			case 7: head = delete_end(head);
					break;
            case 8:	n = nodes(head);
                	printf("Number of nodes = %d\n", n);
                	exit(0);
		}
	}
	return 0;
}
