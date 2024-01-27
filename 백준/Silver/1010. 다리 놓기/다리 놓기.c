#include <stdio.h>

int main() {

    int t;
    scanf("%d",&t);

    long long n,m;
    
    for(int i=0;i<t;i++) {
        scanf("%lld %lld", &n, &m);
        
        long long a=1,b=1,result;
        
        if(m-n<n)
            n=m-n;
        
        while(n>0){
            a*=n;
            n--;
            b*=m;
            m--;
        }
        result=b/a;

        printf("%lld\n",result);


    }

}