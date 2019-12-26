#include<stdlib.h>
#include<stdio.h>
long int fibo(long int a){
	if(a == 0)	return 0;
	else if(a == 1)	return 1;
	else{
		long int x = fibo(a-2);
		long int y = fibo(a-1);
		return x+y;
	}
}
int main(){
	long int a, i, n;
	printf("Enter the number of terms in series : ");
	scanf("%ld", &n);
	for(i = 0; i<=n ; i++){
		a = fibo(i);
		printf("%d ", a);
	}
	printf("\n");
	return 0;
}
