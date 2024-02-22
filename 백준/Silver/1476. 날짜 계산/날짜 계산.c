#include<stdio.h>

int main(){
    int e,s,m;
    scanf("%d %d %d",&e,&s,&m);

    int year=1;

    int E=1,S=1,M=1;

    while(1){

        if(E==16) E=1;
        if(S==29) S=1;
        if(M==20) M=1;


        if(E == e) {
            if (S == s) {
                if (M == m) {
                    printf("%d", year);
                    return 0;
                }
            }
        }
        E++;
        S++;
        M++;

        year++;

    }
}
