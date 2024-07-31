#include <iostream>

using namespace std;

int n,r,c;

long long order=0;

void find_order(long long x,long long y,long long size){

    if(r==x && c==y) {
        cout << order;
        return;
    }

    if( x<=r && y<=c && r < x+size && c < y+size){
        find_order(x,y,size/2);
        find_order(x,y+size/2,size/2);
        find_order(x+size/2,y,size/2);
        find_order(x+size/2,y+size/2,size/2);
    }
    else{
        order+=size*size;
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> r >> c;

    long long size = 1 << n;

    find_order(0,0,size);

}