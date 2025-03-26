//adding two matrices
#include<stdio.h>

void main(){
    int a[100][100],b[100][100],c[100][100],row,col,i,j;
    printf("enter no. of rows and columns:");
    scanf("%d %d",&row,&col);

    printf("enter elements for a:\n");
    for (i=0; i<row; i++)
        for (j=0; j<col; j++)
            scanf("%d",&a[i][j]);
    printf("enter elements for b:\n");
    for (i=0; i<row; i++)
        for (j=0; j<col; j++)
            scanf("%d",&b[i][j]);

    printf("a is:\n");
    for (i=0; i<row; i++)
        {for (j=0; j<col; j++)
            printf("%d ",a[i][j]);
        printf("\n");
        }
    printf("\nb is:\n");
    for (i=0; i<row; i++)
        {for (j=0; j<col; j++)
            printf("%d ",b[i][j]);
        printf("\n");
        }

    //elements added to for matrix c
    for (i=0; i<row; i++)
        for (j=0; j<col; j++)
            c[i][j]=a[i][j]+b[i][j];

    printf("\nelements added to for matrix c:\n");
    for (i=0; i<row; i++)
        {for (j=0; j<col; j++)
            printf("%d ",c[i][j]);
        printf("\n");
        }
}
