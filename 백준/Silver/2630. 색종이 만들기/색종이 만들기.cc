#include <iostream>
using namespace std;

int n;

int white=0;
int blue=0;

int paper[128][128]={};

void cut_paper(int x,int y,int size){

    bool changed = false;


    for(int i=x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
            if(paper[i][j]!= paper[x][y]){
                changed=true;
                break;
            }
        }
    }

    if(changed){
        cut_paper(x,y,size/2);
        cut_paper(x+size/2,y,size/2);
        cut_paper(x,y+size/2,size/2);
        cut_paper(x+size/2,y+size/2,size/2);
    }

    if(paper[x][y]==0 && !changed)
        white++;
    else if(paper[x][y]==1 && !changed)
        blue++;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> paper[i][j];
        }
    }

    cut_paper(0,0,n);

    cout << white <<"\n" << blue;

}
