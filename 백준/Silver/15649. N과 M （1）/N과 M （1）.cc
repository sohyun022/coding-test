#include <iostream>

using namespace std;

int n,m;
int visited[9]={};
int s[9]={};

void BT(int depth){
    if(depth==m){
        for(int i=0;i<m;i++){
            printf("%d ",s[i]);
        }
        printf("\n");
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=1;
            s[depth]=i+1;
            BT(depth+1);
            visited[i]=0;
        }
    }
}


int main() {

    cin >> n >> m;

    BT(0);
    
}