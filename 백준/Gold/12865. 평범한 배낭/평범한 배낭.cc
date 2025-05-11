#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int k;

    cin >> n >> k;
    int w,v;

    vector<pair<int,int>> items;

    vector<vector<int>> dp(n,vector<int>(k+1,0));

    for(int i=0;i<n;i++){
        cin >> w >> v;
        items.emplace_back(v,w);
    }

    for(int j=0;j<=k;j++){
        if(j >= items[0].second)
            dp[0][j]=items[0].first;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            if(j < items[i].second)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-items[i].second]+items[i].first);
        }
    }
    cout << dp[n-1][k];

}
