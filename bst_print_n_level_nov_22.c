#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *rchild;
	struct node *lchild;
};
typedef struct node *NODE;
NODE getnode(int data){
	NODE q = (NODE)malloc(sizeof(struct node));
	q->data = data;
	if(q == NULL){
		printf("Memory not allocated!\n");
		exit(0);
	}
	return q;
}
NODE insert(NODE head, int data){
	if(head == NULL){
		NODE q = getnode(data);
		return q;
	}
	else if(head->data > data){
		head->lchild = insert(head->lchild, data);
	}
	else if(head->data <= data){
		head->rchild = insert(head->rchild, data);
	}
	return head;
}
void level_display(NODE root, int n, int l){
	if(root != NULL){
		if(n == l){
			printf("%d ", root->data);
			return;
		}
		else{
			level_display(root->lchild, n, (l+1));
			level_display(root->rchild, n, (l+1));
		}
	}
	return;
}
void preorder(NODE t){
	if(t == NULL)	return;
	printf("%d ", t->data);
	preorder(t->lchild);
	preorder(t->rchild);
}
int main(){
	NODE root = NULL;
	int choice, ele;
	printf("1. Insert\n2. Print preorder\n3. Print n level elements\n4. Exit\n");
	do{
		printf(">> ");
		scanf("%d", &choice);
		switch(choice){
			case 1: printf("Enter the element to insert : ");
					scanf("%d", &ele);
					root = insert(root, ele);
					break;
			case 2: preorder(root);
					printf("\n");
					break;
			case 3: printf("Enter the level : ");
					scanf("%d", &ele);				//ele = level
					level_display(root, ele, 1);	//levels start from 1
					printf("\n");
					break;
			case 4: return 0;
		}
	}while(choice != 4);
}
