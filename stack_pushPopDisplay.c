//Program to Push, Pop, and Display elements in an array.

#include<stdio.h>
void push(int a[100], int ele, int *z);
void display(int a[100], int *z);
int pop(int a[100], int *z);
int main(){
    int arr[100], choice, cont, size, i, z=-1;
    printf("Enter the total number of elements - \n");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        printf("Enter element %d- ",i);
        scanf("%d", &arr[i]);
        z++;
    }
    do{
        printf("\n1. Push\n2. Pop\n3. Display\nEnter the operation number - ");
        scanf("%d",&choice);
        switch(choice){
        case 1: {
                printf("\nEnter the element to push to array-\n");
                int b;
                scanf("%d", &b);
                push(arr,b,&z);
                break;
        }
        case 2: {
                int x;
                x=pop(arr, &z);
                if(x!=-9999)
                    printf("Popped element is %d\n", x);
                break;
        }
        case 3: display(arr, &z);
        }
        printf("\nDo you want to repeat?\n(Enter 1 for yes, 0 for no)-");
        scanf("%d", &cont);
    }while(cont==1);
    return 0;
}
void push(int a[], int ele, int *z){
    if(*z==99){
        printf("Stack overflow\n");
        return;
    }
    *z=*z+1;
    a[*z]=ele;
}
void display(int a[], int *z){
    if(*z==-1){
        printf("Stack is empty\n");
        return;
    }
    printf("The elements currently in the array are -\n");
    int i;
    for(i=0;i<=*z;i++){
        printf("%d ",a[i]);
    }
}
int pop(int a[], int *z){
    if(*z==-1){
        printf("Stack underflow\n");
        return -9999;
    }
    return a[(*z)--];
}
