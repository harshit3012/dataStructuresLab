//Program to print a given number of elements in a the Fibonacci series
//1BM18CS036
#include<stdio.h>
double fib(double a);
int main(){
	int n, i, a;
	printf("Enter the Number of series -\n");
 	scanf("%d", &n);
 	for(i = 0 ; i < n ; i++){
 		a = fib(i);
 		printf("%d ", a);
	}
	printf("\n");
	return 0;
}
double fib(double a){
	double x, y;
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
