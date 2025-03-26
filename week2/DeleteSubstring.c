 //delete a substring

#include <stdio.h>
#include <string.h>

void main(){
    char str[100],s[100];
    int flag=0;
    printf("enter a string:");
    gets(str);
    printf("enter substring:");
    gets(s);

    int i=0;int j=0;int k;
    int strLen = strlen(str);
    int subLen = strlen(s);

    for (i = 0; i <= strLen-subLen; i++) {
        flag = 1;
        for (j = 0; j < subLen; j++)
            if (str[i + j] != s[j]) {
                flag = 0;
                break;
            }

        if (flag == 1) { //substring found-deletion
            for (k = i; k <= strLen - subLen; k++)
                str[k] = str[k + subLen];
            strLen -= subLen;
            i--; //check for overlapping substrings
        }
    }
    printf("String after deletion of substring:");
    puts(str);
}
