#include <stdio.h>
int hash_p[10000001]={};
int hash_n[10000001]={};
int main() {
    int n;
    scanf("%d",&n);
    int card;

    for(int i=0;i<n;i++){
        scanf("%d",&card);
        if(card<0)
            hash_n[-card]=1;
        else
            hash_p[card]=1;
    }

    int m;
    scanf("%d",&m);
    int num;

    for(int i=0;i<m;i++){
        scanf("%d",&num);
        if(num<0)
            printf("%d ",hash_n[-num]==1);
        else
            printf("%d ",hash_p[num]==1);
    }
}