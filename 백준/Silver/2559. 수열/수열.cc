#include <iostream>
using namespace std;

int main() {
    int n,k;

    cin >> n >> k;

    int temp[n];

    for(int i=0;i<n;i++){
        cin >> temp[i];
    }

    int sum[n-k+1];

    sum[0]=0;

    for(int i=0;i<k;i++){
        sum[0]+=temp[i];
    }

    for(int i=1;i<=n-k;i++){
        sum[i]=sum[i-1]-temp[i-1]+temp[k+i-1];
    }
    int greatest=sum[0];

    for(int s : sum){
        if(s> greatest){
            greatest=s;
        }
        //cout << s << endl;
    }

    cout << greatest;
}
