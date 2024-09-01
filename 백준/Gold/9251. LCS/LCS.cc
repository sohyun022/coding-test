#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a;
    string b;

    cin >> a >> b;

    vector<vector<int>> v(a.size()+1,vector<int>(b.size()+1,0));

    int row=a.size()+1;
    int column = b.size()+1;

    const auto A = a.c_str();
    const auto B = b.c_str();

    int lcs=0;

    for(int i=1;i<row;i++){
        for(int j=1;j<column;j++){

            if(A[i-1]==B[j-1]){

                if(v[i-1][j-1]){
                    v[i][j]=v[i-1][j-1]+1;
                }

                else
                    v[i][j]=1;
            }

            else
                v[i][j]=max(v[i][j-1],v[i-1][j]);

            lcs=max(lcs,v[i][j]);

        }
    }

    cout << lcs ;

}