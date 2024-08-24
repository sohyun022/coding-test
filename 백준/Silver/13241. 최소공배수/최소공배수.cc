#include <iostream>

long long gcd(long long a,long long b){
    if(b==0) return a;

    else{
        return gcd(b,a%b);
    }
}

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a,b;
    cin >> a >> b;

    if(a>b){
        swap(a,b);
    }

    cout << a*b/gcd(a,b);
    
}