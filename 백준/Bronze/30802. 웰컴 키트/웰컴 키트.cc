#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int T_size[6];

    for(int i=0;i<6;i++){
        cin >> T_size[i];
    }

    int T,P;

    cin >> T >> P;

    int totalT=0;

    for(int t : T_size){
        totalT += t/T;
        if(t%T) totalT++;
    }

    cout << totalT << "\n" << n/P << " " << n%P;

    return 0;
}
