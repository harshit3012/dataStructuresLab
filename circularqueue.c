#include<stdio.h>
#define size 10
void insert(int item, int *r, int q[], int *f){
	if((*f == *r+1)||(*f == 0 && *r == (size-1))){
		printf("Queue is full\n");
		return;
	}
	if(*f==-1)
		*f = 0;
	*r = (*r+1)%size;
	q[*r] = item;
}

int delete(int q[], int *f, int *r){
	int item;
	if((*f == -1) || (*f == *r)){
		printf("Queue is empty\n");
		return -9999;
	}
	else{
		item=q[*f];
		if(*f == *r){
			*f =- 1;
			*r = -1;
		}
		else{
			*f = (*f + 1) % size;
			return item;
		}
	}
}
void display(int q[], int f, int r){
	int i;
	if(f == -1){
		printf("Queue is empty\n");
		return;
	}
	printf("Elements in the circular queue are:\n");
	for(i = f ; i != r ; i = (i+1) % size){
		printf("%d\n", q[i]);
	}
	printf("%d\n", q[i]);
}
int main(){
	int n,f=-1,item,r=-1,ele,q[size];
	while(n!=0){
		printf("Enter your choice -\n");
		printf("1. Insertion\n2. Deletion\n3. Display\n4. Quit\n");
		scanf("%d", &n);
		switch(n){
		case 1: {
				printf("Enter an element to insert - ");
				scanf("%d", &item);
				insert(item, &r, q, &f);
				break;
				}
		case 2: {
				ele = delete(q, &f, &r);
				printf("Deleted elemet is %d\n",ele);
				break;
				}
		case 3: {
				display(q, f, r);
				break;
				}
		case 4: return 0;
		default:printf("Please enter a valid choice\n");
		}
	}
	return 0;
}
