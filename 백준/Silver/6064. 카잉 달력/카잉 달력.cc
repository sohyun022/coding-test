#include <iostream>

using namespace std;

int gcd(int a,int b){

    if(b==0) return a;

    return gcd(b,a%b);
}

int lcm(int a,int b){

    return a/gcd(a,b)*b;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    int m,n;
    int x,y;

    for(int i=0;i<t;i++){
        cin >> m >> n;

        int tmpX=m;
        int tmpY=n;

        if(tmpX<tmpY) swap(tmpX,tmpY);
        cin >> x >> y;

        int max=lcm(tmpX,tmpY);

        while(x <= max || y <= max){

            if(x==y){
                cout << x << "\n";
                break;
            }
            if(x<y){
                x+=m;
            }
            else{
                y+=n;
            }
        }

        if(x>max){
            cout << "-1\n";
        }

    }

}