#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

vector<int> nums;
vector<int> seq;

void rec(int depth, int k){

    if(depth==m){
        for(int num : seq){
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    int lastNum=0;

    for(int i=k;i<n;i++){
        if(lastNum != nums[i]){
            seq[depth]=nums[i];
            lastNum = seq[depth];
            rec(depth+1,i);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    nums.resize(n,0);
    seq.resize(m,0);

    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    sort(nums.begin(),nums.end());

    rec(0,0);

}
