//String Concatenation

#include <stdio.h>
#include <string.h>

void main(){
    char str1[100], str2[100],s[100];
    printf("enter 1st string:");
    gets(str1);
    printf("enter 2nd string:");
    gets(str2);
    int len=strlen(str1)+strlen(str2);
    int i=0;
    while(str1[i]!='\0'&&i<len){
        s[i]=str1[i];
        i++;
    }
    i=0;int j=strlen(str1);
    while(str2[i]!='\0'&&i<len){
        s[j]=str2[i];
        i++;j++;
    }
    printf("Concatenated string is:");
    puts(s);
}
