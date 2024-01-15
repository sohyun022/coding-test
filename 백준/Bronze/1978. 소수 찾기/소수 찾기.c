#include <stdio.h>
int PrimeNum(int n){
    for(int i=2;i<n;i++){
        if(n%i==0) return 0;
    }
    return 1;

}
int count=0;
int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=1&&PrimeNum(a[i])) count++;
    }
    printf("%d",count);

}