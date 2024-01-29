#include <stdio.h>


int main() {
    int k;
    scanf("%d",&k);
    long long sum=0;
    long long a[k];
    int n=0;
    for(int i=0;i<k;i++){
        scanf("%lld",&a[n]);

        if(a[n]==0){
            sum-=a[n-1];
            a[n-1]=0;
            n-=1;
        }
        else
            sum+=a[n++];
    }

    printf("%lld",sum);

}