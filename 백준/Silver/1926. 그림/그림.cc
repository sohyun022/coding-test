#include <iostream>
using namespace std;

int n,m;
int painting[500][500]={};
int visited[500][500]={};
int g=0;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void dfs(int i,int j,int& size){

    size++;

    int x=i;
    int y=j;

    visited[x][y]=1;

    for(int k=0;k<4;k++){
        int X=x+dx[k];
        int Y=y+dy[k];

        if(X>=0 && X<n && Y>=0 && Y<m){
            if(!visited[X][Y] && painting[X][Y]==1){
                visited[X][Y]=1;
                dfs(X,Y,size);
            }
        }
    }

}


 int main(){
     cin >> n >> m;

     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             cin >> painting[i][j];
         }
     }

     int count=0;
     int max_size=0;
     int size;

     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             if(!visited[i][j] && painting[i][j]==1){
                 size=0;
                 dfs(i,j,size);
                 count++;
                 if(size>max_size)
                     max_size=size;
             }
         }
     }

     cout << count << endl << max_size;

    return 0;
}