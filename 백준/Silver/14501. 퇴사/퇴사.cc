#include <iostream>
using namespace std;



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int t[15]={};
    int p[15]={};

    int dp[15]={};

    for(int i=0;i<n;i++){
        cin >> t[i] >> p[i];
    }

    for(int i=n-1;i>=0;i--){
        if(i+t[i]<=n){
            dp[i]+=p[i];
        }

        int candidate=0;

        for(int j=i+1;j<n;j++){
            if(i+t[i]-1<j && dp[j]>candidate){
                candidate=dp[j];
            }
        }

        dp[i]+=candidate;

    }

    int max=0;

    for(int i=0;i<n;i++){
        if(max<dp[i]){
            max=dp[i];
        }
    }
    cout << max;







}

