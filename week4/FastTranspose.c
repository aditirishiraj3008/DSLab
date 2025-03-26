//fast transpose of a sparse matrix
#include <stdio.h>
#define MAX_TERMS 10
#define MAXCOL 10

int s[MAX_TERMS][MAX_TERMS],count=0;
struct sparse                 //sparse mat as structure
{
    int row,col,val;
}a[MAX_TERMS],b[MAX_TERMS];

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

void fast_transpose(term a[],term b[]){
    int row_terms[MAXCOL],starting_pos[MAXCOL];     //*rowterms= no of non zero ele in each col index starting from zero*
    int i,j;                                        //*startingpos= pos of triplet in transpose matrix*
    int num_cols=a[0].col; int num_terms=a[0].val;
    b[0].row=num_cols; b[0].col=a[0].row; b[0].val=num_terms;    //0th index of b
    if(num_terms>0){              //for all nonzero elements
        for (i=0;i<=num_cols;i++)
            row_terms[i]=0;                      //first all 0
        for (i=1;i<=num_terms;i++)
            row_terms[a[i].col]++;               //filling rowterms
        starting_pos[0]=1;
        for (i=1;i<=num_cols;i++)
            starting_pos[i]=starting_pos[i-1]+row_terms[i-1];
        for(i=1;i<=num_terms;i++){
            j=starting_pos[a[i].col]++;
            b[j].row=a[i].col;
            b[j].col=a[i].row;
            b[j].val=a[i].val;
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
    fast_transpose(a,b);
    printf("structure representation of transpose:\n");
    for (int i=0;i<count+1;i++){
        printf("%d ",b[i].row);
        printf("%d ",b[i].col);
        printf("%d ",b[i].val);
        printf("\n");
    }

}
