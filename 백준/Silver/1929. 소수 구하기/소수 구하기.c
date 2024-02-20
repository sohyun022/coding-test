#include <stdio.h>
int PrimeNum[500001]={};
int net[1000001]={};
void Remove(int a,int n){
    int i=1;
    while(a*i<=n){
        net[a*i]=1;
        i++;
    }
}
int main() {
    int m,n;
    scanf("%d %d",&m,&n);

    int count=0;

    for(int i=2;i<=n;i++){

        if(net[i]==0){
            Remove(i,n);
            if(i>=m)
                PrimeNum[count++]=i;
        }
    }
    
    for(int i=0;i<count;i++){
        printf("%d\n",PrimeNum[i]);
    }

    return 0;
}
