#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node *NODE;
NODE getnode(){
    NODE p = (NODE)malloc(sizeof(struct node));
    if(p)   return p;
    printf("Memory not allocated!\n");
    exit(0);
}
void display(NODE head){
    if(!head)	return;
	NODE a = head;
    while(a){
        printf("%d ", a->data);
        a=a->next;
    }
    printf("\n");
    return;
}
NODE swap(NODE head){
    if(!head || !head->next)	return head;
	NODE p = head;	     		//The one before the adding
    NODE a = head;				//Used for traversal
    while(a->next) a=a->next;
    NODE last = a;				//The last always
    a = head;
    while(a->next != last)  a=a->next;
    NODE q = a;					//Last but one
    while((q != p) && (q->next != p)){
        last->next = p->next;
        q->next = NULL;
        a = p;
        p->next = last;
        last = q;
        while(a->next != last)    a=a->next;
        q = a;
		p = p->next->next;
    }
    return head;
}
NODE insert(NODE head){
	NODE p = getnode();
	printf("Insert integer : ");
	scanf("%d", &p->data);
	if(!head)	return p;
	NODE a = head;
	while(a->next)	a=a->next;
	a->next = p;
	return head;
}
void main(){
    NODE head = NULL;
    int choice;
	printf("1. Insert\n2. Display\n3. Swap\n4. Exit\n");	
	do{
		printf(">>> ");
		scanf("%d", &choice);
		switch(choice){
			case 1: head = insert(head);
					break;
			case 2: display(head);
					break;
			case 3: head = swap(head);
					break;
			case 4: free(head);
					return;
		}
	}while(choice != 4);
	return;
}
