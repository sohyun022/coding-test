#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int count;

    if(n/5<=0){
        if(n/3>0&&n%3==0)
            count=n/3;
        else count=-1;
    }
    else{
        int i=0;
        while(1){
            if((n-(n/5-i)*5)%3==0){
                count=n/5-i+(n-(n/5-i)*5)/3;
                break;
            }
            i++;
            if(n/5-i<0) {
                count=-1;
                break;}

        }
    }
    printf("%d",count);


}