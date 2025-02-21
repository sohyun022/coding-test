#include <iostream>
#include <algorithm>

using namespace std;
int n;

vector<int> prices;

int main() {

    cin >> n;

    prices.resize(n);

    for(int i =0;i<n;i++){
        cin >> prices[i];
    }

    int dp[1001]={};


    for(int i =1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i]=max(dp[i-j]+prices[j-1],dp[i]);
            //dp[10]=dp[9]+prices[0]
            //dp[10]=dp[0]+prices[9]
        }
    }
    cout << dp[n];

}