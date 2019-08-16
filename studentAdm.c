//Program to print whether a student qualifies for admission into the college.

#include<stdio.h>
struct stu{
	char id[20];
	int marks, age;
}s[100];
void main(){
	int i, a;
	printf("Enter the total number of students-");
	scanf("%d",&a);
	for(i=0;i<a;i++){
		printf("\nEnter student ID of student %d-",i+1);
		scanf("%s",&s[i].id);
		printf("\nEnter age of the student %d-",i+1);
		scanf("%d",&s[i].age);
		printf("\nEnter the marks of the student %d-",i+1);
		scanf("%d",&s[i].marks);
		if(s[i].age>20 && s[i].marks>0 && s[i].marks<=100){
			printf("\nStudent %s meets the criteria for admission.", s[i].id);
			if(s[i].marks>=65)
				printf("\nStudent %s is eligible for admission into the college and can apply!", s[i].id);
			else
				printf("\nUnfortunately, student %s is ineligible for admission into the college.", s[i].id);
		}
		else
			printf("\nThe student doesn't meet the criteria for admission into the college.");
	}
}
