#include <stdio.h>

int main() {
    int x;
    scanf("%d",&x);
    int count=0,sum=0;

    while(1) {
        sum += count;
        if(sum>=x) break;
        count++;
    }

    if(count%2==0)
        printf("%d/%d",count-(sum-x),1+(sum-x));
    else
        printf("%d/%d",1+(sum-x),count-(sum-x));

}
