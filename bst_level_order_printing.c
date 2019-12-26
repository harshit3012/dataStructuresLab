#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
};
typedef struct node *NODE;
NODE getnode(){
	NODE p = (NODE)malloc(sizeof(struct node));
	return p;
}
NODE insert(NODE head, int ele){
	if(!head){
		NODE p = getnode();
		p->data = ele;
		return p;
	}
	if(head->data > ele){
		head->lchild = insert(head->lchild, ele);
		return head;
	}
	else{
		head->rchild = insert(head->rchild, ele);
		return head;
	}
}
int depth(NODE head, int *max, int l){
	if(!head)	return *max;
	if(*max < l)	*max = l;
	depth(head->lchild, max, l+1);
	depth(head->rchild, max, l+1);
	return *max;
}
void print_at_l(NODE head, int n, int l){
	if(!head){
		printf("-");
		return;
	}
	if(n == l){
		printf("%d ", head->data);
		return;
	}
	print_at_l(head->lchild, n, l+1);
	print_at_l(head->rchild, n, l+1);
	return;
}
void level_print(NODE head){
	if(!head)	return;
	int max = -1;
	int max1 = depth(head, &max, 0);
	int i;
	for(i=0; i<=max1; i++){
		print_at_l(head, i, 0);
		printf("\n");
	}
	return;
}
void preorder(NODE head){
	if(!head)	return;
	printf("%d ", head->data);
	preorder(head->lchild);
	preorder(head->rchild);
	return;
}
void main(){
	int choice, ele, m;
	NODE head = NULL;
	printf("1. Insert\n2. Print preorder\n3. Print depth\n4. Print Level Order\n5. Exit");
	do{
		printf("\n>>> ");
		scanf("%d", &choice);
		switch(choice){
			case 1: printf("Enter element to insert : ");
					scanf("%d", &ele);
					head = insert(head, ele);
					break;
			case 2: preorder(head);
					break;
			case 3: m = -1;
					depth(head, &m, 0);
					if(m == -1){
						printf("Depth is : 0");
						break;
					}
					printf("Depth is : %d", m);
					break;
			case 4: level_print(head);
					break;
			case 5: return;
		}
	}while(choice != 5);
}
