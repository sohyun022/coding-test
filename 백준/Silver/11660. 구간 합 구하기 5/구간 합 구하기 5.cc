#include <iostream>
using namespace std;

int num[1025][1025]={};
int dp[1025][1025]={};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int m;
    cin >> m;

    int x1,y1,x2,y2;
    

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> num[i][j];
            dp[i][j]=dp[i][j-1]+num[i][j];
        }
    }

    for(int i=0;i<m;i++){

        int result=0;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int x=x1;x<=x2;x++){
            result+=dp[x][y2]-dp[x][y1-1];
        }

        cout << result << "\n";
    }

}
