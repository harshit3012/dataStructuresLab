#include<stdio.h>
#include<stdlib.h>
void insertion(int queue[], int *f, int *r);
void display(int queue[], int f, int r);
void new_queue(int queue[], int queue1[], int f, int r, int *f1, int *r1);
char check(int a);
void insert(int queue[], int *f, int *r, int ele);
void main(){
	int f = 0;
	int r = -1;
	int f1 = 0;
	int r1 = -1;
	int queue[10];
	int queue1[10];
	int n, i; 				//For the size of Input Queue
	int choice;
	printf("Operations :\n1. Add element to Input Queue\n2. Display Input Queue\n3. Display Output Queue\n4. Exit\n");
	do{
		printf("Choose operation : ");
		scanf("%d", &choice);
		switch(choice){
			case 1: insertion(queue, &f, &r);
					break;
			case 2: printf("Input Queue is : ");
					display(queue, f, r);
					break;
			case 3: printf("Output Queue is : ");
					f1 = 0;
					r1 = -1;
					new_queue(queue, queue1, f, r, &f1, &r1);
					display(queue1, f1, r1);
					break;
			case 4: printf("Program Terminated by the user!!\n");
					exit(0);
		}
	}while(choice != 4);
}
void insertion(int queue[], int *f, int *r){
	if(*r == 9){
		printf("Overflow!\n");
		return;
	}
	printf("Enter element to insert : ");
	int ele;
	scanf("%d", &ele);
	*r = *r + 1;
	queue[*r] = ele;
	return;
}
void display(int queue[], int f, int r){
	if(r == -1){
		printf("Empty!!\n");
		return;
	}
	int i;
	for(i = f; i <=r; i++){
		printf("%d  ", queue[i]);
	}
	printf("\n");
	return;
}

void new_queue(int queue[], int queue1[], int f, int r, int *f1, int *r1){
	if(r == -1){
		printf("Empty Input Queue!\n");
		return;
	}
	int j;
	for(j = f; j <= r; j++){
		if(check(queue[j]) == 'Y'){
			insert(queue1, f1, r1, queue[j]);
		}
	}
	return;
}

char check(int a){
	if((a % 2520) == 0){
		return 'Y';
	}
	else{
		return 'N';
	}
}
void insert(int queue[], int *f, int *r, int ele){
	if(*r == 9){
		printf("Overflow!\n");
		return;
	}
	*r = *r + 1;
	queue[*r] = ele;
	return;
}
