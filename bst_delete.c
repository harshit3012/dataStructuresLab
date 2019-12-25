#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *rchild;
	struct node *lchild;
};
typedef struct node *NODE;
NODE getnode(int a){
	NODE p = (NODE)malloc(sizeof(struct node));
	if(!p)	exit(0);
	p->data=a;
	return p;
}
NODE insert(NODE head, int key){
	if(!head){
		head = getnode(key);
		return head;
	}
	if(head->data > key)	head->lchild = insert(head->lchild, key);
	else if(head->data < key)	head->rchild = insert(head->rchild, key);
	return head;
}
void preorder(NODE head){
	if(!head)	return;
	printf("%d ", head->data);
	preorder(head->lchild);
	preorder(head->rchild);
}
int maxhead(NODE head);
NODE delete(NODE head, int key){
	if(!head)	return head;
	if(head->data > key){
		head->lchild = delete(head->lchild, key);
		return head;
	}
	else if(head->data < key){
		head->rchild = delete(head->rchild, key);
		return head;
	}

	else{							//When the node->data = key
		if(!head->lchild){
			NODE temp = head->rchild;
			free(head);
			return temp;
		}
		else if(!head->rchild){
			NODE temp = head->lchild;
			free(head);
			return temp;
		}
		else{
			head->data = maxhead(head->lchild);
			head->lchild = delete(head->lchild, head->data);
		}
	}
	return head;
}
int maxhead(NODE head){
	if(!head)	return 0;
	if(!head->rchild){
		return head->data;
	}
	return maxhead(head->rchild);
}
int search(NODE head, int key){
	NODE p = head;
	while(p!=NULL){
		if(p->data > key)	p=p->lchild;
		else if(p->data < key)	p=p->rchild;
		else	return 1;
	}
	free(p);
	return 0;
}
void main(){
	NODE root = NULL;
	int choice, ele;
	printf("1. Insert\n2. Search\n3. Display\n4. Delete\n5. Exit\n");
	do{
		printf(">>> ");
		scanf("%d", &choice);
		switch(choice){
			case 1: printf("Enter element to insert : ");
					scanf("%d", &ele);
					root = insert(root, ele);
					break;
			case 2: printf("Enter key to search : ");
					scanf("%d", &ele);
					if(search(root, ele))
							printf("Found!\n");
					else
							printf("Not found!\n");
					break;
			case 3: preorder(root);
					printf("\n");
					break;
			case 4: printf("Enter key to delete : ");
					scanf("%d", &ele);
					root = delete(root, ele);
					break;
			case 5: return;
		}
	}while(choice!=5);
	return;
}
