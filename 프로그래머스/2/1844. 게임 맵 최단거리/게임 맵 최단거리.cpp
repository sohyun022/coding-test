#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> MAPS;
int mps[100][100]={};
int n,m;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

queue<pair<int,int>> q;

int solution(vector<vector<int>> maps)
{
    n= maps.size();
    m= maps[0].size();

    q.emplace(0,0);
    mps[0][0]=1;

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int X=x+dx[i];
            int Y=y+dy[i];

            if(X>=0 && X<n && Y>=0 && Y<m 
               && maps[X][Y] && !mps[X][Y]){
               
                mps[X][Y]=mps[x][y]+1;
                if(X==n-1 && Y==m-1)
                    return mps[X][Y];
                q.emplace(X,Y);
                
            }
        }
    }
    return -1;
}