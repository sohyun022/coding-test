#include <string>
#include <vector>
#include <queue>

using namespace std;
// 주어진 좌표 두 배로 저장하기
// 맵에 사각형 그리기(다른 사각형 내부와 겹치는 경우 그리지 않음)
// 다각형의 아웃라인을 제외하고 지우기(사각형 내부는 2로 표시)
// bfs 탐색

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    
    int path[101][101]={};
    bool visited[101][101]={};
        
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
        
    int answer=0;
    
    for(auto& rect: rectangle){
        for(int i=0;i<4;i++){
            rect[i] *= 2; //좌표 두 배
        }

        for(int i=rect[0];i<=rect[2];i++){
            for(int j=rect[1];j<=rect[3];j++){
                if(path[i][j]==2) //사각형의 내부의 위치한 지점
                    continue; 
                path[i][j]=1; //사각형 그리기
            }
        }

        for(int i=rect[0]+1;i<rect[2];i++){
            for(int j=rect[1]+1;j<rect[3];j++){
                path[i][j]=2; //사각형 내부
            }
        }
    }

    queue<pair<int,int>> q;
    q.emplace(characterX*2, characterY*2);
    visited[characterX*2][characterY*2]=true;

    int newX,newY;

    while(!q.empty()){

        int q_size=q.size();

        for(int i=0;i<q_size;i++){
            int curX = q.front().first;
            int curY = q.front().second;

            if(curX==itemX*2 && curY==itemY*2)
                return answer/2;
            
            q.pop();

            for(int i=0;i<4;i++){
                newX=curX+dx[i];
                newY=curY+dy[i];

                if(newX >= 0 && newX < 101 && newY >= 0 && newY < 101 
                   && path[newX][newY]==1 && !visited[newX][newY]){
                    q.emplace(newX,newY);
                    visited[newX][newY] = true;
                }
            }
        }
        answer++;
    } 
}