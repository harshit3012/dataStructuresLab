#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node *NODE;
NODE getnode(){
    NODE p = (NODE)malloc(sizeof(struct node));
    if(p == NULL){
        printf("Mem not allocated!!\n");
        exit(0);
    }
    return p;
}
NODE insert_end(NODE head, int ele){
    NODE p = getnode();
    p->data = ele;
    if(head == NULL){
        p->next = NULL;
        return p;
    }
    NODE q = head;
    while(q->next != NULL){
        q = q->next;
    }
    q->next = p;
    return head;
}
int ll_sum(NODE head){
    if(head == NULL){
        return 0;
    }
    int sum = 0;
    NODE q = head;
    while(q != NULL){
        sum = sum + q->data;
        q = q->next;
    }
    return sum;
}
NODE del_head(NODE head){
    if(head == NULL){
        return NULL;
    }
    return head->next;
}
int biggest(int a, int b, int c){
    if (a > b){
        if(a > c) return 1;
        else return 3;
    }
    else{
        if(b > c) return 2;
        else return 3;
    }
}
void display(NODE head){
    NODE q = head;
    while(q){
        printf("%d ", q->data);
        q = q->next;
    }
    printf("\n");
}
int main(){
    NODE head1 = NULL;
    NODE head2 = NULL;
    NODE head3 = NULL;
    int len1, len2, len3, size1, size2, size3, i, val;
    printf("Enter the number of Cylinders in stacks 1, 2, and 3 : ");
    scanf("%d %d %d", &len1, &len2, &len3);
    printf("Enter the heights of %d Cylinders in Stack 1 : ", len1);
    for(i = 0; i < len1; i++){
        scanf("%d", &val);
        head1 = insert_end(head1, val);
    }
    //display(head1);
    size1 = ll_sum(head1);
    //printf("Size1 = %d\n", size1);
    printf("Enter the heights of %d Cylinders in Stack 2 : ", len2);
    for(i = 0; i < len2; i++){
        scanf("%d", &val);
        head2 = insert_end(head2, val);
    }
    //display(head2);
    size2 = ll_sum(head2);
    //printf("Size2 = %d\n", size2);
    printf("Enter the heights of %d Cylinders in Stack 3 : ", len3);
    for(i = 0; i < len3; i++){
        scanf("%d", &val);
        head3 = insert_end(head3, val);
    }
    //display(head3);
    size3 = ll_sum(head3);
    //printf("Size3 = %d\n", size3);
    while(!((size1 == size2) && (size2 == size3))){
        switch(biggest(size1, size2, size3)){
            case 1: head1 = del_head(head1);
                    size1 = ll_sum(head1);
                    //printf("Deleted 1");
                    //display(head1);
                    break;
            case 2: head2 = del_head(head2);
                    size2 = ll_sum(head2);
                    //printf("Deleted 2");
                    //display(head2);
                    break;
            case 3: head3 = del_head(head3);
                    size3 = ll_sum(head3);
                    //printf("Deleted 3");
                    //display(head3);
                    break;
        }
    }
    printf("The Maximum Equal Size is %d\n", size1);
    printf("Finally :\nStack 1 : ");
    display(head1);
    printf("Stack 2 : ");
    display(head2);
    printf("Stack 3 : ");
    display(head3);
    return 0;
}