#include <iostream>
int dp[100]={};

int main() {
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;

    int t;
    std :: cin >>t;

    for(int k=0;k<t;k++){
        int n;
        std :: cin >> n;

        for(int i=4;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }

        std::cout << dp[n] << std::endl;
    }

    return 0;
}
