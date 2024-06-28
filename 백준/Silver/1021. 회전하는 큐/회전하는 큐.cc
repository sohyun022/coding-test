#include <iostream>
#include <deque>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;

    cin >> n >> m;

    int count=0;

    deque<int> cq;


    for(int i=1;i<=n;i++){
        cq.push_back(i);
    }

    int num;

    for(int i=0;i<m;i++){

        cin >> num;

        int index;

        for(int j=0;j<n;j++){
            if(cq[j]==num){
                index=j;
                break;
            }
        }

        while(true){

            if(cq.front()==num){
                cq.pop_front();
                break;
            }

            if(index<=cq.size()/2){
                cq.push_back(cq[0]);
                cq.pop_front();
                count++;
            }

            else{
                cq.push_front(cq[cq.size()-1]);
                cq.pop_back();
                count++;
            }
        }
    }

    cout << count;

}
