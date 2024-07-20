#include <iostream>
using namespace std;

int n;
int dp[1000]={};
int val[1000]={};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> val[i];
    }

    int max=0;

    for(int i=n-1;i>=0;i--){
        dp[i]=1;
        
        for(int j=i+1;j<n;j++){
            if(val[j]>val[i] && dp[j]+1>dp[i])
                dp[i]=dp[j]+1;

        }
        
        if(dp[i]>max)
            max=dp[i];
    }

    cout << max;

}