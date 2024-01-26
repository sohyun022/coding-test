#include <stdio.h>
int main(){
    int black[100][100]={};
    int n;
    int x,y;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        for(int j=x;j<x+10;j++){
            for(int k=y;k<y+10;k++){
                black[j][k]=1;
            }
        }
    }
    int count=0;

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(black[i][j]==1)
                count++;
        }

    }

    printf("%d",count);


}