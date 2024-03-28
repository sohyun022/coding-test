#include <iostream>
#include <algorithm>
using namespace std;

void p_search(const int *tree,int n,int m){

    long left = 0;
    long right = tree[n-1];
    long max = 0;

    while(left<=right){
        long height=(left+right)/2;
        long sum = 0;

        for(int i=0;i<n;i++){
            if(tree[i]>height)
                sum+=tree[i]-height;
        }

        if(sum>=m){
            if(max<height){
                max= height;
            }
            left = height + 1;
        }
        else
            right = height - 1;

    }

    cout << max;

}

int main() {
    int n,m;
    cin >> n >> m;
    int tree[n];

    for(int i=0;i<n;i++){
        cin >> tree[i];
    }

    sort(tree,tree+n);

    p_search(tree,n,m);

}
