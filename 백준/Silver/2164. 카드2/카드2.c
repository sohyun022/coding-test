#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);

    int card[2*n];

    for(int i=1;i<=n;i++){
        card[i]=i;
    }

    int start=1;
    int end=n;

    while(1){
        if(start==end) break;
        card[start++]=0;
        card[++end]=card[start];
        start++;

    }
    printf("%d",card[end]);

}