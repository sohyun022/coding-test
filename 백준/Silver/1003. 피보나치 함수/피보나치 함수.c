#include <stdio.h>

int main(){

    int call0[41]={1,0};
    int call1[41]={0,1};

    for(int i=2;i<41;i++){
        call0[i]=call0[i-1]+call0[i-2];
        call1[i]=call1[i-1]+call1[i-2];
    }
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        printf("%d %d\n",call0[n],call1[n]);

    }
}