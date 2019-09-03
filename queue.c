#include<stdio.h>
#include<stdlib.h>
void enque(int q[], int *r);
void deque(int q[], int *r, int *f);
void display(int q[], int r, int f);
void main(){
	int q[80], front = 0, rear =- 1, ch;
	while(1){
		printf("1. Enque\n2. Deque\n3. Display\n4. Exit\n");
		printf("Enter the choice - ");
  		scanf("%d", &ch);
  		switch(ch){
   			case 1:{
   				enque(q, &rear);
          			break;
          		}
   			case 2:{
   				deque(q, &rear, &front);
        			break;
        		}
   			case 3:{
   				display(q, rear, front);
         			break;
         		}
   			case 4: exit(0);
		}
	}
}
void enque(int q[], int *r){
	int ele;
 	if(*r == 79)
	 	printf("Queue is full");
	else{
		printf("Enter the element to be added - ");
		scanf("%d", &ele);
 		*r = *r + 1;
 		q[*r] = ele;
 	}
}
void deque(int q[], int *r, int *f){
	if(*f > *r)
		printf("Queue is empty\n");
		return;
 	else{
 		printf("Deleted element = %d\n", q[*f]);
 		*f = *f + 1;
	}
}
void display(int q[], int r, int f){
	int i;
	if(f == r)
		printf("Queue is empty\n");
		return;
	else{
		printf("Elements of queue\n");
 		for(i = f ; i <= r ; i++)
 		printf("%d \n", q[i]);
	}
}
