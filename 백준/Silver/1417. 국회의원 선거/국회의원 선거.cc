#include <iostream>
#include <queue>
using namespace std;
int main(){

    int n;
    cin >> n;

    int num;

    cin >> num;

    int have = num;

    int count=0;

    if(n==1) {
        cout << 0;
        return 0;
    }


    priority_queue <int> candidate;
    for(int i=1;i<n;i++){
        cin >> num;
        candidate.push(num);
    }
    while(true){
        if(have<=candidate.top()){
            int tmp=candidate.top();
            candidate.pop();
            candidate.push(tmp-1);
            have++;
            count++;
        }

        else{
            cout << count;
            break;
        }

    }









}
