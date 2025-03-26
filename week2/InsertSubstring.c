//Insertion of substring

#include <stdio.h>
#include <string.h>

void main(){
    char str[100],s[100],temp[100];
    int index;
    printf("enter a string:");
    gets(str);
    printf("enter substring:");
    gets(s);
    int len=strlen(s);
    int lenstr=strlen(str);
    printf("index for it to be inserted:");
    scanf("%d",&index);

    for(int j=0;j<(lenstr-len);j++)
        temp[j]=str[index+j];
    int i=0;
    while(str[i]!='\0'){
        str[index]=s[i];
        str[index+1]=str[index];
        i++;
        index++;
    }
    strcat(str,temp);
    printf("String after insertion of substring:");
    puts(str);
}
