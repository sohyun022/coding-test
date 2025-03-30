#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int num;
    int sum=0;
    int Max=-1000;

    for(int i=0;i<n;i++){
        cin >> num;

        if( num > 0){
            if(sum < 0)
                sum = num;
            else
                sum += num;
        }

        else{
            if(sum + num > 0 )
                sum += num;
            else
                sum = num;

        }

        Max = max(sum, Max);


    }
    cout << Max;
}
