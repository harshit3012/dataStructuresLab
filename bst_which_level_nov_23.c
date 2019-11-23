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
void which_level(NODE root, int l, int key, int *found, int *which){
    if(*found)  return;
    if(root == NULL)    return;
    if(key == root->data){
        *found = 1;
        *which = l;
        return;
    }
    which_level(root->lchild, (l+1), key, found, which);
    which_level(root->rchild, (l+1), key, found, which);
    return;
}
int main(){
    int choice, ele, level, which;
    int found = 0;
    NODE root = NULL;
    printf("1. Insert\n2. Display preorder\n3. Display the level of a given element\n4. Exit\n");
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
            case 3: which = 0;
                    found = 0;
                    printf("Integer whose level is to be found : ");
                    scanf("%d", &ele);
                    which_level(root, 0, ele, &found, &which);			//Second argument is 0 as levels start from 0
                    if(found){
                        printf("Found and the level of %d is %d\n", ele, which);
                    }
                    else{
                        printf("Not Found!\n");
                    }
                    break;
            case 4: return 1;
        }
    }while(choice != 4);
    return 1;
}
