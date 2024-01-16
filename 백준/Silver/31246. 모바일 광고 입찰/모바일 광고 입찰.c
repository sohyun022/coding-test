#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b){
    if (*(long long*)a>*(long long*)b) return 1;
    else return-1;
}

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    long long a[n],b[n],c[n];

    for(int i=0;i<n;i++) {
        scanf("%lld %lld", &a[i], &b[i]);
        c[i] = b[i] - a[i];

    }

    int count=0;
    long long x=0;
    int p;
    qsort(c,n,sizeof(long long),compare);
    int rest;
    for(int i=0;i<n;i++){
        if(c[i]<=0) count++;
        else {p=i; break;}
    }

//    for(int i=0;i<n;i++){
//        printf("%lld ",c[i]);
//    }

    if(count>=k) {
        printf("%lld",x);
        }

    else{
        rest=k-count;
        x+=c[p-1+rest];
        printf("%lld",x);

    }
    return 0;







//while(1) {
//    for (int i = 0; i < n; i++) {
//        if (a[i] + x >= b[i])
//            count++;
//    }
//    if (count >= k){
//        printf("%d",x);
//        break;
//    }
//
//    x++;
//    count = 0;
//}
}


