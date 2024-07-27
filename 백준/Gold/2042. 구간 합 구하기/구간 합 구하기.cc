#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void init(vector<long long> &a, vector<long long> &tree, long long node, long start, long end) {

    if (start == end) {
        tree[node] = a[start];
    }
    else {
        init(a, tree, node*2, start, (start+end)/2);
        init(a, tree, node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

long long query(vector<long long> &tree, long long node, long long start, long long end, long long left, long long right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    long long lsum = query(tree, node*2, start, (start+end)/2, left, right);
    long long rsum = query(tree, node*2+1, (start+end)/2+1, end, left, right);
    return lsum + rsum;
}

void update(vector<long long> &tree, long long node, long long start, long long end, long long index, long long diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(tree,node*2, start, (start+end)/2, index, diff);
        update(tree,node*2+1, (start+end)/2+1, end, index, diff);
    }
}
void update(vector<long long> &a, vector<long long> &tree, long long n, long long index, long long val) {
    long long diff = val - a[index];
    a[index] = val;
    update(tree, 1, 0, n-1, index, diff);
}

 int main(){

     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);

    int n,m,k;

    cin >> n >> m >> k;

     vector<long long> a(n);

     long h = (int)ceil(log2(n));
     long long tree_size = (1 << (h+1));
     vector<long long> tree(tree_size);


    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    init(a,tree,1,0,n-1);

     long long A,B,C;

    for(int i=0;i<m+k;i++){

        cin >> A >> B >> C;

        if(A==1){
            update(a,tree,n,B-1,C);
        }
        else if(A==2){
            cout << query(tree,1,0,n-1,B-1,C-1) << "\n";
        }

    }

    return 0;
}