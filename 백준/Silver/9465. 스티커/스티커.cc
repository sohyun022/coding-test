#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int stickers[2][n];

        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin >> stickers[i][j];
            }
        }

        int dp[2][n];

        dp[0][0]=stickers[0][0];
        dp[1][0]=stickers[1][0];
        

        if(n>1){
            dp[0][1]=dp[1][0]+stickers[0][1];
            dp[1][1]=dp[0][0]+stickers[1][1];

            for(int j=2;j<n;j++){
                dp[0][j]=max(dp[1][j-2],dp[1][j-1])+stickers[0][j];
                dp[1][j]=max(dp[0][j-2],dp[0][j-1])+stickers[1][j];
            }
        }

        cout << max(dp[0][n-1],dp[1][n-1]) <<"\n";
    }

}