#include <stdio.h>
int main() {
    int n;
    int count[42]={};
    for(int i=0;i<10;i++){
        scanf("%d",&n);
        count[n%42]++;
    }
    int cnt=0;
    for(int i=0;i<42;i++){
        if(count[i]!=0)
            cnt++;
    }
    printf("%d",cnt);
}