#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n,m;
    int x,y;

    cin >> n >> m;

    vector <int> wall(n,1);

    for(int i=0;i<m;i++){
        cin >> x >> y;

        for(int k=x-1;k<y-1;k++){
            wall[k]=0;
        }

    }

    long cnt= count(wall.begin(), wall.end(),1);


    cout << cnt;

}
