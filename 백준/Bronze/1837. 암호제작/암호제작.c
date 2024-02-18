#include<stdio.h>
#include <string.h>
//int isPrime(int i){
//    for(int j=2;j<i;j+=2){
//        if(i%j==0)
//            return 0;
//    }
//    return 1;
//}
int main(){
    char P[102];
    int k;
    scanf("%s %d",P,&k);

    int q;

    for(int i=2;i<k;i++){

//        if(isPrime(i)){
            int num=0;

            for(int j=0;j<strlen(P);j++){
                num=(num*10 + P[j]-'0') % i;
            }

            if(num==0){
                q=i;
                printf("BAD %d",q);
                return 0;
            }
//        }
    }
    printf("GOOD");
}