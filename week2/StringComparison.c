//string comparison

#include <stdio.h>
#include <string.h>

void main(){
    char str1[100], str2[100];
    printf("enter 1st string:");
    gets(str1);
    printf("enter 2nd string:");
    gets(str2);
    int len1=strlen(str1);
    int len2=strlen(str2);

    for(int i=0;i<len1&&i<len2;i++)
        if(str1[i]!=str2[i]){
            printf("Strings not equal");
            exit(0);
        }
    printf("Strings are equal");
}
