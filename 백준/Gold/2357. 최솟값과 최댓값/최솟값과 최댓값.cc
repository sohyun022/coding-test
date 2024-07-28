#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void init(vector<long long> &arr, vector<long long> &treemin,vector<long long> &treemax, long long node, long start, long end) {

    if (start == end) {
        treemin[node] = arr[start];
        treemax[node] = arr[start];
    }
    else {
        init(arr, treemin,treemax, node*2, start, (start+end)/2);
        init(arr, treemin,treemax, node*2+1, (start+end)/2+1, end);
        treemin[node] = min(treemin[node*2], treemin[node*2+1]);
        treemax[node] = max(treemax[node*2], treemax[node*2+1]);
    }
}

long long query_min(vector<long long> &tree, long long node, long long start, long long end, long long left, long long right) {
    if (left > end || right < start) {
        return -1;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    long long lmin = query_min(tree, node*2, start, (start+end)/2, left, right);
    long long rmin = query_min(tree, node*2+1, (start+end)/2+1, end, left, right);

    if(lmin == -1) return rmin;
    else if(rmin == -1) return lmin;
    else return min(lmin,rmin);
}

long long query_max(vector<long long> &tree, long long node, long long start, long long end, long long left, long long right) {
    if (left > end || right < start) {
        return -1;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    long long lmax = query_max(tree, node*2, start, (start+end)/2, left, right);
    long long rmax = query_max(tree, node*2+1, (start+end)/2+1, end, left, right);

    if(lmax == -1) return rmax;
    else if(rmax == -1) return lmax;
    else return max(lmax,rmax);
}


 int main(){

     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);

    int n,m;

    cin >> n >> m ;

     vector<long long> arr(n);

     long h = (int)ceil(log2(n));
     long long tree_size = (1 << (h+1));
     vector<long long> treemin(tree_size);
     vector<long long> treemax(tree_size);


    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    init(arr,treemin,treemax,1,0,n-1);

    int a,b;

    for(int i=0;i<m;i++){

        cin >> a >> b;

        cout << query_min(treemin,1,0,n-1,a-1,b-1) << " ";
        cout << query_max(treemax,1,0,n-1,a-1,b-1) << "\n";

    }

    return 0;
}