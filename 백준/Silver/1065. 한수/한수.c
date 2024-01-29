#include <stdio.h>
int hansu(int i){
    int d=i%10-(i/10)%10;
    if(i>=100){
        while(1){
            i/=10;
            if(d!=i%10-(i/10)%10)
                return 0;
            if(i<100)
                return 1;
        }
    }
    else
        return 1;
    }

int main() {
    int n;
    scanf("%d",&n);
    int count=0;
    for(int i=1;i<=n;i++){
        if(hansu(i))
            count++;
    }
    printf("%d",count);
}