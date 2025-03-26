//To find the length of a string

#include <stdio.h>

void main(){
    char str[100]; int len=0;
    printf("enter a string:");
    gets(str);

    int i=0;
    while(str[i]!='\0'){
        len++;
        i++;
    }
    printf("length is %d",len);
}
