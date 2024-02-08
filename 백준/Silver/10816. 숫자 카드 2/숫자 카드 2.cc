#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}

int n;
int num[500000];
int posi[10000001];
int nega[10000001];

int bs1(int s){
    int l =0;
    int r = n-1;
    int middle;
    while(l<=r){
        middle = (l+r)/2;
        if(num[middle] < s) l = middle+1;
        else r = middle-1;
    }
    return l;
}

int bs2(int s){
    int l =0;
    int r = n-1;
    int middle;
    while(l<=r){
        middle = (l+r)/2;
        if(num[middle] <= s) l = middle+1;
        else r = middle-1;
    }
    return l;
}

int main() {

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    qsort(num,n,sizeof(int),compare);

    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++) {
        int temp;
        scanf("%d", &temp);
        int l = bs1(temp);
        int r = bs2(temp);
        int ans = r-l;
        printf("%d ",ans);
    }
    return 0;
}
