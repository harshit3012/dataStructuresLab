#include<stdio.h>
int fib(int a);
int main(){
	int n, i, a;
	printf("Enter the Number of values in the series -\n");
 	scanf("%d", &n);
 	for(i = 0 ; i < n ; i++){
 		a = fib(i);
 		printf("%d ", a);
	}
	printf("\n");
	return 0;
}
int fib(int a){
	int x, y;
	if((a==0)){
		return 0;
	}
	else if(a==1){
		return 1;
	}
	else{
		x = fib(a-1);
  		y = fib(a-2);
		return(x + y);
	}
}

