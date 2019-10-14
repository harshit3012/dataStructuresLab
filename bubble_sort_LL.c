#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node *NODE;
void swap1(NODE a, NODE b);
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
void delete(NODE head, int ele){
	if(head == NULL){
		printf("Empty List!!\n");
		return;
	}
	NODE ptr = head;
	NODE pptr = NULL;
	while(ptr->data != ele){
		pptr = ptr;
		if(ptr->next == NULL){
			printf("Not Found!\n");
			return;
		}
		ptr = ptr->next;
	}
	pptr = ptr->next;
	printf("Deleted %d\n", ptr->data);
	free(ptr);
	return;
}
void bubblesort(NODE head){
	if(head == NULL){
		printf("List is empty!\n");
		return;
	}	
	int swapped = 0;
	NODE lptr = NULL;
	NODE ptr;
	do{
		swapped = 0;
		ptr = head;
		while(ptr->next != lptr){
			if((ptr->data) > (ptr->next->data)){
				swap1(ptr, ptr->next);
				swapped = 1;
			}
			if(ptr->data == ptr->next->data)
				delete(head, ptr->data);
			ptr = ptr->next;
		}
		display(head);
		lptr = ptr;
	}while(swapped);
}
void swap1(NODE a, NODE b){
	printf("Swapped %d -> %d\n", a->data, b->data);
	int temp = b->data;
	b->data = a->data;
	a->data = temp;
	return;
}
int main(){
    NODE head = NULL;
    int choice, ele, value;
	printf("1. Insert at the Front\n2. Bubble Sort\n3. Display\n4. Exit\n");
	do{
		printf("Enter option : ");
		scanf("%d", &choice);
		switch(choice){
			case 1: printf("Enter element to be inserted : ");
					scanf("%d", &ele);
					head = insert_beg(head, ele);
					break;
			case 2: bubblesort(head);
					break;
			case 3:	printf("Elements in list are ");
					display(head);
					break;
			case 4: exit(0);
		}
	}while(choice != 4);
	return 0;
}
