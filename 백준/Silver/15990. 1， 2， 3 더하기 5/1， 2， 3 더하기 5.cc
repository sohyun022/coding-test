#include <iostream>
using namespace std;

#define MOD 1000000009

long dp[100001][4]={};
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    dp[1][1]=1;

    dp[2][2]=1;

    dp[3][1]=1;
    dp[3][2]=1;
    dp[3][3]=1;


    for(int i=4;i<=100000;i++){

        dp[i][1]=dp[i-1][2]%MOD +dp[i-1][3]%MOD;
        dp[i][2]=dp[i-2][1]%MOD +dp[i-2][3]%MOD;
        dp[i][3]=dp[i-3][1]%MOD +dp[i-3][2]%MOD;

    }

    int n;

    while(t--){
        cin >> n;
        long total=0;

        for(auto a : dp[n]){
            total+=(a%MOD);
        }

        cout << total%MOD <<"\n";
    }
}