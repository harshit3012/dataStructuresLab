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
void preorder(NODE t){
	if(t == NULL)	return;
	printf("%d ", t->data);
	preorder(t->lchild);
	preorder(t->rchild);
}
void height1(NODE root, int l, int *z){
    if(root == NULL)    return;
    if(l > *z){
        *z = l;
    }
    height1(root->lchild, (l+1), z);
    height1(root->rchild, (l+1), z);
    return;
}
int main(){
    int choice, ele;
    int ht = 0;
    NODE root = NULL;
    printf("1. Insert\n2. Display preorder\n3. Display height of BST\n4. Exit\n");
    do{
        printf(">>> ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter element to insert : ");
                    scanf("%d", &ele);
                    root = insert(root, ele);
                    break;
            case 2: preorder(root);
                    printf("\n");
                    break;
            case 3: ht = 0;
                    height1(root, 0, &ht);		//Second argument is 0 as levels start from 0
                    printf("Height is %d\n", ht);
                    break;
            case 4: return 1;
        }
    }while(choice != 4);
    return 1;
}
