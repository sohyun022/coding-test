#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    long long dp[101][101]={};

    for(int i=1;i<=9;i++){
        dp[1][i]=1;
    }

    for(int i=2;i<=100;i++){
        for(int j=0;j<=9;j++){
            if(j>0 && j<9){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) %1000000000;
            }
            else if(j==0){
                dp[i][j] = dp[i-1][j+1];
            }
            else{
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }

    long long result=0;

    for(int i=0;i<=9;i++){
        result = (result + dp[n][i]) % 1000000000;
    }

    cout << result;
}