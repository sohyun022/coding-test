#include <stdio.h>
void CMPLTN(int n){
    int num[n-1];
    int sum=0;
    int count=0;
    for(int i=1;i<n;i++){
        if(n%i==0){
            num[count++]=i;
            sum+=i;
        }
    }
    if(n==sum) {
        printf("%d =",n);
        for(int i=0;i<count;i++){
            printf(" %d ",num[i]);
            if(i!=count-1)
                printf("+");
            else
                printf("\n");
        }
    }
    else
        printf("%d is NOT perfect.\n",n);


}
int main() {
    while(1){
        int n;
        scanf("%d",&n);

        if(n<2||n>100000) break;

        CMPLTN(n);
    }

}