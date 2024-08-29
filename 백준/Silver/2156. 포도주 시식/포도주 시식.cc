#include <iostream>
#include <algorithm>

using namespace std;

int wine[10000];
int dp[3][10000]={};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> wine[i];
    }

    dp[1][0]=wine[0];
    dp[2][0]=wine[0];

    for(int j=1;j<n;j++){
        dp[0][j]=max(dp[2][j-1],max(dp[1][j-1],dp[0][j-1]));
        dp[1][j]=dp[0][j-1]+wine[j];
        dp[2][j]=dp[1][j-1]+wine[j];
    }

    int maxWine = max(dp[0][n - 1], max(dp[1][n - 1], dp[2][n - 1]));

    cout << maxWine;
}