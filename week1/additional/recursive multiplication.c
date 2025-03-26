#include <stdio.h>

int Multiply(int a,int b) {
    if (b== 0)
        return 0;

    if (b> 0)
        return (a+Multiply(a,b-1));
}
void main() {
    int a,b;
    printf("Enter two no.s: ");
    scanf("%d %d", &a,&b);

    int result = Multiply(a,b);
    printf("Result of %d*%d = %d\n", a,b,result);
}
