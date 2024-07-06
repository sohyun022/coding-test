#include <iostream>
#include <algorithm>
using namespace std;

int n;
char home[25][25]={};
int visited[25][25]={};
int complex[400]={};

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void bfs(int x,int y,int count){
    visited[x][y]=1;

    for(int i=0;i<4;i++){
        int X=x+dx[i];
        int Y=y+dy[i];

        if(X>=0 && X<n && Y>=0 && Y<n)
            if(home[X][Y]=='1' && !visited[X][Y]){
                complex[count]++;
                bfs(X,Y,count);
            }
    }

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> home[i][j];
        }
    }

    int count=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(home[i][j]=='1' && !visited[i][j]){
                complex[count]++;
                bfs(i,j,count);
                count++;
            }
        }
    }

    cout << count << endl;

    sort(complex,complex+count);

    for(int i=0;i<count;i++){
        cout << complex[i] << endl;
    }

}
