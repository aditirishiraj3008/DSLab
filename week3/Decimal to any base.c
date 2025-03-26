#include<string.h>
#define MAXSIZE 100

int stack[MAXSIZE];
int rem,item,dec,top=-1;

void PUSH(int item){
    if(top==MAXSIZE-1){
        printf("Stack full\n");
        return;
    }
    stack[++top]=item;
}
int POP(){
    if(top==-1){
        printf("Stack underflow\n");
        return;
    }
    return stack[top--];
}
void base(int n){
    int a=dec;
    if (a == 0) {
        return 0;
    }
    while (a!=0){
        rem=a%n;
        a=a/n;
        PUSH(rem);
    }
    while(top!=-1){
        rem=POP();
        if (rem>=10)                //for hexa
            printf("%c",(char)(rem+55));
        else
            printf("%d",rem);
    }
}

void main(){
    int n;
    printf("enter a dec no.:");
    scanf("%d",&dec);
    printf("\nin binary:");
    base(2);
    printf("\nin octal:");
    base(8);
    printf("\nin hexadec:");
    base(16);
}
