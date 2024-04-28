#include <iostream>
using namespace std;
int n,m;

int arr[8]={};

void sq(int depth,int k){

    if(depth==m){
       for(int i=0;i<m;i++)
           cout << arr[i] << " ";
        cout <<"\n";
        return;
    }

    for(int i=k;i<=n;i++){
        arr[depth]=i;
        sq(depth+1,i);
    }



}

int main() {
    cin >> n >> m;
    sq(0,1);
}
