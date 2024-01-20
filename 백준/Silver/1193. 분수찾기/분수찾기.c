#include <stdio.h>
int count=0;
void FindLine(int n){
    if(n<=0) return;

    count++;
    n=n-count;
    FindLine(n);
}
int main() {
    int x;
    scanf("%d",&x);
    FindLine(x);

    int sum=0;
    for(int i=1;i<=count;i++){
        sum+=i;
    }

    if(count%2==0)
        printf("%d/%d",count-(sum-x),1+(sum-x));
    else
        printf("%d/%d",1+(sum-x),count-(sum-x));
    
}