#include <stdio.h>
int count=1;
int num(long n){
    if(n/10==0)
        return count++;
    else {
        count++;
        return num(n/10);
    }
}
int main() {
    long n;
    scanf("%ld",&n);

    int length=num(n);
    long a=n-9*length; //생성자
    long b=0; //생성자 각 자리수 합
    long c;

    while(1){

        c=a;
        for(int i=0;i<length;i++){
            b+=c%10;
            c/=10;
        }

        if(a+b==n){
            break;
        }
        else if(a>=n){
            a=0;
            break;
        }
        a++;
        b=0;
    }
    printf("%ld",a);
}

