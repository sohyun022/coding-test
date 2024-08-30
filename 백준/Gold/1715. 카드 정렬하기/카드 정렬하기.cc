#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;

int total=0;
int cards[100000]={};

void cardArranging(){

    priority_queue<int,vector<int>,greater<>> pq;

    for(int i=0;i<n;i++){
        pq.push(cards[i]);
    }

    while(true){
        int tmp=pq.top();
        pq.pop();

        tmp+=pq.top();
        pq.pop();

        total+=tmp;

        if(pq.empty())
            return;

        pq.push(tmp);

    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> cards[i];
    }

    if(n>1)
        cardArranging();

    cout << total;

}