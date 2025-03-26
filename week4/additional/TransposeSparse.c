//transpose of sparse matrix
#include <stdio.h>
#define MAX_TERMS 10

int s[MAX_TERMS][MAX_TERMS],count=0;
struct sparse                 //sparse mat as structure
{    int row,col,val;
} a[MAX_TERMS], b[MAX_TERMS];

typedef struct sparse term;

void to_sparse(int x,int y){
    int i,j,k=1;              //k-line in which row,col,val of ele
    for(i=0;i<x;i++)
        for(j=0;j<y;j++){
            if(s[i][j]!=0){
                count++;
                a[k].row=i;
                a[k].col=j;
                a[k].val=s[i][j];
                k++;
            }
            a[0].row=x;           //first line in stuct
            a[0].col=y;
            a[0].val=count;
        }
}

void transpose(term a[],term b[]){
    int i,j,currentb=1;            //currentb-index
    b[0].row=a[0].col;
    b[0].col=a[0] .row;
    b[0].val=a[0].val;
    if(a[0].val>0){
        for(i=0;i<a[0].col;i++)
            for(j=1;j<a[0].val;j++)     //columnwise reading
                if(a[j].col==i){
                    b[currentb].row=a[j].col;
                    b[currentb].col=a[j].row;
                    b[currentb].val=a[j].val;
                    currentb++;
                }
    }
}

int main(){
    int i,j,m,n;
    printf("enter no. of rows, cols of sparse matrix:\n");
    scanf("%d %d",&m,&n);
    printf("enter elements:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&s[i][j]);
    to_sparse(m,n);

    printf("structure representation of sparse:\n");
    for (int i=0;i<count+1;i++){
        printf("%d ",a[i].row);
        printf("%d ",a[i].col);
        printf("%d ",a[i].val);
        printf("\n");
    }
    transpose(a,b);
    printf("structure representation of transpose:\n");
    for (int i=0;i<count+1;i++){
        printf("%d ",b[i].row);
        printf("%d ",b[i].col);
        printf("%d ",b[i].val);
        printf("\n");
    }

}
