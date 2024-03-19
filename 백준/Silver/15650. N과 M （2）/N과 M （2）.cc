#include <iostream>

using namespace std;
int n,m;
int visited[9];
int sequence[9];

void BackTracking(int depth,int k){
    if(depth==m){
        for(int i=0;i<m;i++){
            printf("%d ",sequence[i]);
        }
        printf("\n");
    }

    for(int i=k;i<n;i++){
        if(!visited[i]){
            visited[i]=1;
            sequence[depth]=i+1;
            BackTracking(depth+1,i+1);
            visited[i]=0;
        }
    }
}

int main() {

    cin >> n >> m;

    BackTracking(0,0);

}