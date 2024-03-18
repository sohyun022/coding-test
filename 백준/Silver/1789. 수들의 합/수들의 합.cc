#include <iostream>

using namespace std;

int main() {

    long long s;
    cin >> s;

    int n=1;
    long long sum=0;

    while(true) {
        sum += n;
        if(sum>s) {
            n--;
            break;
        }
        n++;
    }
    cout << n;
}
