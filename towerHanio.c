#include<stdio.h>
void tower(int n, char a, char b, char c);
int main(){
	int n;
	printf("Enter the number of plates: ");
	scanf("%d", &n);
	tower(n, 'A', 'B', 'C');
	return 0;
}
void tower(int n, char a, char b, char c){
	if(n == 1){
		printf("1 Plate is moved from %c to %c\n", a, c);
	}
	else if(n > 0){
		tower(n-1, a, c, b);
		printf("%d Plate is moved\t %c >> %c\n", n, a, c);
		tower(n-1, b, a, c);
	}
} 
