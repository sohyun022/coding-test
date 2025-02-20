#include <iostream>
#include <algorithm>

using namespace std;
int main() {

    int n;
    cin >> n;

    int prevMin[3];
    int curMin[3];
    
    int prevMax[3];
    int curMax[3];

    int score[3];

    for(int i =0; i<3 ;i++){
        cin >> prevMin[i];
        prevMax[i] = prevMin[i];
    }

    for(int i =1; i <n ;i++){
        for(int j=0;j<3;j++){
             cin >> score[j];
        }

        curMax[0]=max(prevMax[0],prevMax[1])+score[0];
        curMax[1]=max({prevMax[0],prevMax[1],prevMax[2]})+score[1];
        curMax[2]=max(prevMax[1],prevMax[2])+score[2];

        curMin[0]=min(prevMin[0],prevMin[1])+score[0];
        curMin[1]=min({prevMin[0],prevMin[1],prevMin[2]})+score[1];
        curMin[2]=min(prevMin[1],prevMin[2])+score[2];

        for(int j =0 ;j<3;j++){
            prevMax[j] = curMax[j];
            prevMin[j] = curMin[j];
        }
    }

    cout << max({prevMax[0],prevMax[1],prevMax[2]}) << " "
    << min({prevMin[0],prevMin[1],prevMin[2]});
}
