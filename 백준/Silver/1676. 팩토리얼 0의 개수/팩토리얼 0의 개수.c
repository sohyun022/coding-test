#include <stdio.h>
int cnt=0;
int five(int n){
    n/=5;
    cnt++;
    if(n%5!=0)
        return cnt;
    else
        return five(n);
}
int main() {
    int n;
    scanf("%d", &n);
    int factorial[501]={};

    for(int i=0;i<=n;i++){
        factorial[i]=i;
    }

    int count=0;

    for(int i=1;i<=n;i++){
        if(factorial[i]%5==0){
            cnt=0;
            count+=five(factorial[i]);
        }
    }

    printf("%d",count);
}