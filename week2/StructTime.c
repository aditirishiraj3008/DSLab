#include<stdio.h>
#include<string.h>
struct Time{
    int hour,min,sec;
}time[100];

void Add(int a,int b){
    int hsum=time[a].hour+time[b].hour;
    int msum=time[a].min+time[b].min;
    int ssum=time[a].sec+time[b].sec;
    if(ssum>=60){
        ssum-=60;
        msum+=1;}
    if(msum>=60){
        msum-=60;
        hsum+=1;}
    printf("sum is: %d hrs %d min %d sec",hsum,msum,ssum);
}
void Subtract(int a,int b) {
    int hdiff = time[a].hour-time[b].hour;
    int mdiff = time[a].min-time[b].min;
    int sdiff = time[a].sec-time[b].sec;
    if (sdiff < 0) {
        sdiff += 60;
        mdiff -= 1;
    }
    if (mdiff < 0) {
        mdiff += 60;
        hdiff -= 1;
    }
    printf("Difference is: %d hrs %d min %d sec\n", hdiff, mdiff, sdiff);
}

void main(){
    int n;
    printf("enter no. of records of time:");
    scanf("%d",&n);

    for(int i=0;i<n;i++){                            //reading
        printf("\nenter details of time %d:\n",i+1);
        printf("enter hours:");
        scanf("%d",&time[i].hour);
        printf("enter minutes:");
        scanf("%d",&time[i].min);
        printf("enter seconds:");
        scanf("%d",&time[i].sec);
    }
                                                            //displaying info
    for(int i=0;i<n;i++){
        printf("\ndetails of time %d",i+1);
        printf("\nhours:%d",time[i].hour);
        printf("\nminutes:%d",time[i].min);
        printf("\nseconds:%d",time[i].sec);
        printf("\n");
    }
    int x,y;
    printf("enter 2 time for finding sum and diff in time:");
    scanf("%d %d",&x,&y);
    x--;y--;
    Add(x, y);
    Subtract(x, y);
}
