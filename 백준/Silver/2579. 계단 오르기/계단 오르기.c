#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int floor[301];
    int dp[301]={};

    for(int i=1;i<=n;i++){
        scanf("%d",&floor[i]);
    }

    dp[0]=0;
    dp[1]=floor[1];
    dp[2]=dp[1]+floor[2];

    for(int i=3;i<=n;i++){
        dp[i]=dp[i-3]+floor[i-1]>dp[i-2]?dp[i-3]+floor[i-1]:dp[i-2];
        dp[i]+=floor[i];
    }
    printf("%d",dp[n]);

}