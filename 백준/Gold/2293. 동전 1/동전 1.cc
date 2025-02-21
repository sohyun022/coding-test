#include <iostream>
#include <algorithm>

using namespace std;

int n,k;

int main() {
    cin >> n >> k;

    vector<int> coin(n,0);

    for(int i =0;i<n;i++){
        cin >> coin[i];
    }

    sort(coin.begin(),coin.end());

    long long dp[10001]={};

    dp[0]=1;

    for(int i =0;i< n;i++){
        for(int j=coin[i];j<=k;j++){
            if(j >= coin[i])
                dp[j]+=dp[j-coin[i]];
        }
    }

    cout << dp[k];
}