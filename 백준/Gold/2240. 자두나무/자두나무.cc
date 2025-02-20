#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int t,w;

    cin >> t >> w;

    int tree[t+1];

    for(int i =1;i<=t;i++){
        cin >> tree[i];
    }

    int dp[1001][31]={};

    for(int j=0;j<=w;j++){
        if ((j % 2 == 0 && tree[1] == 1) || (j % 2 == 1 && tree[1] == 2))
            dp[1][j] = 1;
    }

    for(int i=2;i<=t;i++){
        for(int j =0;j <=w; j++){

            dp[i][j]=dp[i-1][j];

            if((j%2 == 0 && tree[i] ==1) || j%2 == 1 && tree[i] ==2)
                dp[i][j] =dp[i][j]+1;

            if(j>0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (tree[i] == (j % 2 + 1) ? 1 : 0));
        }
    }

    int maxPlum=0;

    for(int i =0;i<=w;i++){
        maxPlum = max(maxPlum,dp[t][i]);
    }

    cout << maxPlum;

}