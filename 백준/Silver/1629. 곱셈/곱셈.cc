#include <iostream>
using namespace std;

long long a,b,c,k;

long long power(long long B){
    if(B==1) return a%c;

    k=power(B/2) %c;

    if(B%2==0){
        return k*k%c;
    }
    else
        return k*k%c*a%c;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> c;

    cout << power(b);

}
