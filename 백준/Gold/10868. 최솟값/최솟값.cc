#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector <long long> arr;
vector<long long> tree;

long long Min;

void mktree(long long index,long long start,long long end){
    if(start==end)
        tree[index]=arr[start];

    else{
        mktree(index*2,start,(start+end)/2);
        mktree(index*2+1,(start+end)/2+1,end);
        tree[index]=min(tree[index*2],tree[index*2+1]);
    }
}

void query(long long index,long long start,long long end,long long left,long long right){
    
    if(left > end || right < start)
        return;

    if(left <= start && right >= end){
        Min=min(tree[index],Min);
        return;
    }

    query(index*2,start,(start+end)/2,left,right);
    query(index*2+1,(start+end)/2+1,end,left,right);

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

        Min=LLONG_MAX;

        cin >> a >> b;

        query(1,0,n-1,a-1,b-1);

        cout << Min << "\n";

    }

    return 0;
}
