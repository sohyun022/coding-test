#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> arr;
vector<long long> tree;

void mktree(long long index,long long start,long long end){

    if(start==end)
        tree[index]=arr[start];

    else{
        mktree(index*2,start,(start+end)/2);
        mktree(index*2+1,(start+end)/2+1,end);
        tree[index]=min(tree[index*2],tree[index*2+1]);
    }

}

long long query(long long index,long long start,long long end,long long left,long long right){

    if(left > end || right < start)
        return -1;

    if(left <= start && right >= end){
        return tree[index];
    }

    long long lmin = query(index*2, start, (start+end)/2, left, right);
    long long rmin = query(index*2+1, (start+end)/2+1, end, left, right);

    if (lmin == -1) {
        return rmin;
    }

    else if (rmin == -1) {
        return lmin;
    }

    else {
        return min(lmin, rmin);
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    arr.resize(n);

    int h=(int)ceil(log2(n));
    long long tree_size=(1 << (h+1));

    tree.resize(tree_size);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    mktree(1,0,n-1);

    int a,b;

    for(int i=0;i<m;i++){

        cin >> a >> b;

        cout << query(1,0,n-1,a-1,b-1) << "\n";

    }

    return 0;
}
