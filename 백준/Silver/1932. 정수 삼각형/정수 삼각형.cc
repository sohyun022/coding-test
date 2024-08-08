#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> tri;
vector<vector<int>> dp;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    tri.resize(n,vector<int>(n,0));
    dp.resize(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin >> tri[i][j];
        }
    }

    dp[0][0]=tri[0][0];

    for(int i=1;i<n;i++){
        for(int j=0;j<i+1;j++){
            if(j==0) dp[i][j]=dp[i-1][j]+tri[i][j];
            else if(j==i) dp[i][j]=dp[i-1][j-1]+tri[i][j];
            else{
                if(dp[i][j]<dp[i-1][j-1]+tri[i][j])
                    dp[i][j]=dp[i-1][j-1]+tri[i][j];
                if(dp[i][j]<dp[i-1][j]+tri[i][j])
                    dp[i][j]=dp[i-1][j]+tri[i][j];
            }
        }
    }

    int max=0;

    for(int j=0;j<n;j++){
        if(dp[n-1][j]>max)
            max=dp[n-1][j];
    }

    cout << max;

}
