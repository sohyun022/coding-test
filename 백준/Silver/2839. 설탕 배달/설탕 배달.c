#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int count=0;
    while(n%5!=0&&n>=3){
        n-=3;
        count++;

    }
    if(n%5!=0)
        count=-1;
    else
        count+=n/5;

    printf("%d",count);

}