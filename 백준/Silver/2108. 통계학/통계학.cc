#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

int main() {
    int n;
    cin >> n;

    double a;
    int b,c,d;

    vector <int> arr(n);
    vector <int> visited(8001,0);
    vector <int> n_count(8001,0);
    vector <int> maxs;

    int sum=0;
    int max_c=0;

    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum+=arr[i];
        n_count[arr[i]+4000]++;
    }

    a=(int)round((sum/(double)n));

    sort(arr.begin(),arr.end());

    b=arr[(n-1)/2];

    for(int i=0;i<n;i++){

        if(n_count[arr[i]+4000]>max_c){
            max_c=n_count[arr[i]+4000];
            maxs.resize(0);
            maxs.push_back(arr[i]);
            visited[arr[i]+4000]=1;
        }
        else if(n_count[arr[i]+4000]==max_c && !visited[arr[i]+4000]){
            maxs.push_back(arr[i]);
            visited[arr[i]+4000]=1;
        }
    }

    sort(maxs.begin(),maxs.end());

    if(maxs.size()>1){
        c=maxs[1];
    }
    else
        c=maxs[0];

    d=arr.back()-arr.front();

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;

}