#include <iostream>
#include <algorithm>
using namespace std;


int compare(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}

bool visited[10001]={};

int sq[8];

int arr[8];
int n,m;

void sequence(int depth){

    if(depth==m){
        for(int i=0;i<m;i++){
            cout << sq[i] << " ";
        }
        cout << "\n";

        return;

    }

    for(int i=0;i<n;i++){
        if(!visited[arr[i]]){
            visited[arr[i]]=true;
            sq[depth]=arr[i];
            sequence(depth+1);
            visited[arr[i]]=false;
        }
    }


}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m;


    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    qsort(arr,n,sizeof(int),compare);


    sequence(0);


}
