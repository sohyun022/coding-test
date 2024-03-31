#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t,n,m;
    cin >> t;
    int num;

    for(int i=0;i<t;i++){
        vector<int> diary;

        cin >> n;

        for(int j=0;j<n;j++){
            cin >> num;
            diary.push_back(num);
        }

        sort(diary.begin(),diary.end());

        cin >> m;

        for(int k=0;k<m;k++){
            cin >> num;
            if(binary_search(diary.begin(),diary.end(),num))
                cout << "1\n";
            else
                cout << "0\n";
        }

    }


    return 0;
}
