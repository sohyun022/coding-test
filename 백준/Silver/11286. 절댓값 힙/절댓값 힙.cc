#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct compare{
    bool operator()(int a,int b) const {
        if(abs(a) > abs(b)) return true;

        else if(abs(a) == abs(b)){
            if(a>b) return true;
        }

        return false;
    }
};

priority_queue<int,vector<int>,compare> abs_heap;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int x;

    for(int i=0;i<n;i++){
        cin >> x;

        if(x==0){
            if(!abs_heap.empty()){
                cout << abs_heap.top() << "\n";
                abs_heap.pop();
            }
            else
                cout << "0" << "\n";
        }

        else{
            abs_heap.push(x);
        }
    }

}