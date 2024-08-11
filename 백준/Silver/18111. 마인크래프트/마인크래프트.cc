#include <iostream>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    long b;
    cin >> n >> m >> b;

    int min=256;

    int map[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j] < min)
                min = map[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            b+= map[i][j]-min;
        }
    }

    long plusHeight = min + b/(n*m);

    int minTime=256*500*500;
    int totalTime;
    int height;

    for(int h = min; h <= plusHeight; h++){

        totalTime=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(map[i][j] > h)
                    totalTime += (map[i][j]-h)*2;

                else if(map[i][j]<h)
                    totalTime += (h-map[i][j]);
            }
        }

        if(totalTime == minTime && h>height)
            height=h;

        if(totalTime < minTime){
            minTime=totalTime;
            height=h;
        }
        
    }

    cout << minTime << " " << height;

}
