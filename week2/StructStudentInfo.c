#include<stdio.h>
#include<string.h>
struct student{
    char name[100];
    int rollno;
    char grade[10];
}students[100];

void main(){
    int n;
    printf("enter no. of students:");
    scanf("%d",&n);

    for(int i=0;i<n;i++){                            //reading
        printf("\nenter name of student %d:",i+1);
        scanf("%s",students[i].name);
        printf("enter rollno.:");
        scanf("%d",&students[i].rollno);
        printf("enter grade:");
        scanf("%s",students[i].grade);
        printf("\n");
    }

    for(int i=0;i<n-1;i++)                           //sorting according to rollno
        for(int j=0;j<n-1-i;j++)
            if(students[j].rollno>students[j+1].rollno){
                struct student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }

    printf("\nStudent information\n");                 //displaying info
    for(int i=0;i<n;i++){
        printf("\ndetails of student %d",i+1);
        printf("\nname:%s",students[i].name);
        printf("\nrollno.:%d",students[i].rollno);
        printf("\ngrade:%s",students[i].grade);
        printf("\n");
    }

}
