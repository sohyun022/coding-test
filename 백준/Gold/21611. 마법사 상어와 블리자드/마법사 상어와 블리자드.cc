#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int grid[50][50]; // 격자
pair<int,int> blizzad[100]; // 마법 주문
vector<pair<int,int>> path;

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

int score[4] = {0, 0, 0, 0};

// 격자 번호와 위치 좌표 매핑하기
void mapping(){
    int X[]={0,1,0,-1};
    int Y[]={-1,0,1,0};
    int len=1; // 같은 방향이 반복될 횟수
    int dir=0; // 방향 번호

    int x= n/2;
    int y= n/2;

    while(true){
        for(int i=0;i<2;i++){ // len 마다 두 번씩 반복
            for(int j=0;j<len;j++){
                x+=X[dir];
                y+=Y[dir];

                if (x < 0 || y < 0 || x >= n || y >= n) return;
                path.emplace_back(x,y);

            }
            (dir += 1) %= 4; // 방향 변경
        }
        len++;}

}

// 구슬 리스트로 변환
vector<int> to_list() {
    vector<int> beads;
    for (auto p : path) {
        int x = p.first, y = p.second;
        if (grid[x][y])
            beads.push_back(grid[x][y]);
    }
    return beads;
}

// 리스트를 격자로 변환
void to_grid(vector<int>& beads) {
    for (int i = 0; i < path.size(); ++i) {
        int x = path[i].first, y = path[i].second;
        if (i < beads.size()) grid[x][y] = beads[i];
        else grid[x][y] = 0;
    }
}

// 구슬 파괴하기
void crush_beads(int d, int s){
    int x = n / 2, y = n / 2;
    for (int i = 1; i <= s; ++i) {
        int nx = x + dx[d] * i;
        int ny = y + dy[d] * i;
        grid[nx][ny] = 0;
    }
}

bool explode_beads(vector<int>& beads){
    vector<int> new_beads;
    bool exploded = false;

    for (int i = 0; i < beads.size();) {
        int j = i;
        while (j < beads.size() && beads[i] == beads[j]) j++;
        if (j - i >= 4) {
            score[beads[i]] += (j - i);
            exploded = true;
        } else {
            for (int k = i; k < j; ++k) new_beads.push_back(beads[i]);
        }
        i = j;
    }
    beads = new_beads;

    return exploded;
}

vector<int> change_beads(vector<int>& beads){
    vector<int> res;
    for (int i = 0; i < beads.size();) {
        int j = i;
        while (j < beads.size() && beads[i] == beads[j]) j++;
        res.push_back(j - i);
        res.push_back(beads[i]);
        i = j;
    }
    if (res.size() > path.size()) res.resize(path.size());
    return res;
}

int main() {

    cin >> n >> m;

    mapping();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }

    for(int i=0;i<m;i++){
        cin >> blizzad[i].first >> blizzad[i].second; // 주문
    }

    for(int i=0;i<m;i++){
        int d = blizzad[i].first;
        int s = blizzad[i].second;

        crush_beads(d,s);

        vector<int> beads = to_list();

        while(explode_beads((beads)));

        beads = change_beads(beads);
        to_grid(beads);
    }

    cout << score[1] + 2*score[2] + 3*score[3] << endl;

}