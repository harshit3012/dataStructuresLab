#include<stdio.h>
long int multiply(long int a);
int main(){
	long int n;
	long int f;
	printf("Enter the positive number -\n");
	scanf("%ld", &n);
	f = multiply(n);
	printf("Factorial of %ld is %ld\n", n, f);
	return 0;
}
long int multiply(long int a){
	if(a >= 1)
		return a * multiply(a - 1);
	else
		return 1;
}	
