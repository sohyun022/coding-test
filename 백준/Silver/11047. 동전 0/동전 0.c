#include <stdio.h>


int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int count=0;
    int i=n-1;
    while(1){

        if(a[i]<=k)
            count+=k/a[i];

        k=k%a[i--];

        if(k==0) break;

        if(i==0){
            count+=k;
            break;
        }

    }
    printf("%d",count);

}