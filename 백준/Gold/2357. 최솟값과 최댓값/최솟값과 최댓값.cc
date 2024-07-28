#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

vector<long long> arr;
vector<long long> mintr;
vector<long long> maxtr;

long long Min;
long long Max;

void init(long long node, long start, long end) {

    if (start == end) {
        mintr[node] = arr[start];
        maxtr[node] = arr[start];
    }
    else {
        init(node*2, start, (start+end)/2);
        init( node*2+1, (start+end)/2+1, end);
        mintr[node] = min(mintr[node*2], mintr[node*2+1]);
        maxtr[node] = max(maxtr[node*2], maxtr[node*2+1]);
    }
}

void query(long long node, long long start, long long end, long long left, long long right) {

    if (left > end || right < start) {
        return;
    }

    if (left <= start && end <= right) {
        Min=min(mintr[node],Min);
        Max=max(maxtr[node],Max);
        return;
    }

    query( node*2, start, (start+end)/2, left, right);
    query( node*2+1, (start+end)/2+1, end, left, right);

}

 int main(){

     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);

     cin >> n >> m;

     arr.resize(n);

     long h = (int)ceil(log2(n));
     long long tree_size = (1 << (h+1));

     mintr.resize(tree_size);
     maxtr.resize(tree_size);


    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    init(1,0,n-1);

    int a,b;

    for(int i=0;i<m;i++){

        Min=1000000000;
        Max=0;

        cin >> a >> b;

        query(1,0,n-1,a-1,b-1);

        cout << Min << " ";
        cout << Max << "\n";

    }

    return 0;
}