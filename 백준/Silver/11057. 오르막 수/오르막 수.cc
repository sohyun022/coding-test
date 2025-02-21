#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    long dp[1001][10]={};

    for(int i =0;i<=9;i++){
        dp[1][i]=1;
    }

    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=j;k++){
                dp[i][j]=(dp[i][j]+dp[i-1][k])%10007;
            }
        }
    }

    int sum=0;

    for( auto s : dp[n]){
        sum+=s%10007;
    }

    cout << sum%10007;
}