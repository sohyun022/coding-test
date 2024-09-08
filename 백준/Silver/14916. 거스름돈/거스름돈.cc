#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int total=0;

    int five=n/5;
    int two;

    bool flag= false;

    while(five){
        if((n-5*five)%2==0){
            two=(n-5*five)/2;
            flag=true;
            break;
        }
        else{
            five--;
        }
    }

    if(!flag){
        if(n%2==0){
            total=n/2;
        }
        else
            total=-1;
    }
    else
        total=five+two;

    cout << total;
    
}

