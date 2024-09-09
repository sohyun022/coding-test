#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,l;

    cin >> n >> l;

    int leak[n];

    for(int i=0;i<n;i++){
        cin >> leak[i];
    }

    sort(leak,leak+n);

    int edge=leak[0]+l-1;

    int tape=1;

    for(int water : leak){
        if(water > edge){
            tape++;
            edge=water+l-1;
        }
    }

    cout << tape;

}
