#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int,vector<int>,greater<>> pq;

int n;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int x;

    for(int i=0;i<n;i++){
        cin >> x;

        if(x>0){
           pq.push(x);
        }

        else if(x==0){

            if(pq.empty()){
                cout << "0" << "\n";
            }
            else{
                cout << pq.top() <<"\n";
                pq.pop();
            }

        }
    }

}
