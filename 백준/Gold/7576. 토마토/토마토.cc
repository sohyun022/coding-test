#include <iostream>
#include <queue>
using namespace std;

int n,m;

int box[1000][1000]={};
int day[1000][1000]={};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue <pair<int,int>> q;


void bfs() {

    while (!q.empty()) {

        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int X = x + dx[i];
            int Y = y + dy[i];

            if (X >= 0 && X < m && Y >= 0 && Y < n) {
                if (box[X][Y] == 0){
                    box[X][Y]=1;
                    q.emplace(X,Y);
                    day[X][Y]=day[x][y]+1;
                }
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1)
                q.emplace(i, j);
        }
    }

    bfs();

    int max = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (box[i][j] == 0) {
                cout << "-1";
                return 0;
            }
            if (max < day[i][j]) {
                max = day[i][j];
            }
        }
    }

    cout << max;

}
