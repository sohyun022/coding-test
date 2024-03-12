#include <stdio.h>

int main() {

    int a,b,c;

    scanf("%d %d %d",&a,&b,&c);

    int num[10]={};

    long long multi=a*b*c;

    while(multi){
        num[multi%10]++;
        multi/=10;
    }

    for(int i=0;i<10;i++){
        printf("%d\n",num[i]);
    }
}