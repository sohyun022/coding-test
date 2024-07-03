#include <iostream>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    int arr[n+1];

    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    int left=1;
    int right=n;

    int count=0;


    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=i;j<=n;j++){
            sum+=arr[j];
            if(sum==m){
                count++;
                break;
            }
        }
    }

    cout << count;

}
