#include<stdio.h>
#include<stdlib.h>
struct t{
	int data;
	struct t *rchild;
	struct t *lchild;
};
typedef struct t *NODE;
NODE getnode(){
	NODE p = (NODE)malloc(sizeof(struct t));
	if(p == NULL){
		printf("Memory not alocated!\n");
		exit(0);
	}
	return p;
}
NODE insert(NODE root, int ele){
	if(root == NULL){
		NODE q = getnode();
		q->data = ele;
		return q;
	}
	if(ele < root->data){
		root->lchild = insert(root->lchild, ele);
	}
	else if(ele >= root->data){
		root->rchild = insert(root->rchild, ele);
	}
	return root;
}
int search(NODE head, int key){
	NODE root = head;
	while(root != NULL){
		if(key > root->data){
			root = root->rchild;
		}
		else if(key < root->data){
			root = root->lchild;
		}
		else{
			return 1;
		}
	}
	return 0;
}
void inorder(NODE t){
	if(t != NULL){
    	inorder(t->lchild);
    	printf("%d  ",t->data);
    	inorder(t->rchild);
	}
}
void preorder(NODE t){
	if (t == NULL) 
          return;
    printf("%d ", t->data);   
    preorder(t->lchild);
    preorder(t->rchild);
}
void postorder(NODE t){
	if (t == NULL) 
        return;
    postorder(t->lchild);
    postorder(t->rchild);
    printf("%d ", t->data);
}
int main(){
	NODE root = NULL;
	int choice, ele;
	do{
		printf("1. Insert an element\n2. Display tree inorder\n3. Display tree preorder\n4. Display tree post-order\n5. Search of a value\n6. Exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1: printf("Enter integer to insert : ");
					scanf("%d", &ele);
					root = insert(root, ele);
					break;
			case 2: inorder(root);
					printf("\n");
					break;
			case 3: preorder(root);
					printf("\n");
					break;
			case 4: postorder(root);
					printf("\n");
					break;
			case 5: printf("Enter the integer to search : ");
					scanf("%d", &ele);
					if(search(root, ele)){
						printf("Found!\n");
					}
					else{
						printf("Not Found!\n");
					}
					break;
		}
	}while(choice != 6);
	return 0;
}
