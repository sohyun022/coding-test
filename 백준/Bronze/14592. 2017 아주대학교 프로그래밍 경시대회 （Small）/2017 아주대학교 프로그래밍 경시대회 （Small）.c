#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int p[3][3];
    int maxscore=-1;
    int submit;
    int lasttime;
    int winner;

    for(int i=0;i<n;i++){
        scanf("%d %d %d",&p[i][0],&p[i][1],&p[i][2]);
    }

    for(int i=0;i<n;i++){
        if(maxscore<p[i][0]){
            maxscore=p[i][0];
            submit=p[i][1];
            lasttime=p[i][2];
            winner=i;
        }
        else if(maxscore==p[i][0]){
            if(submit>p[i][1]){
                submit=p[i][1];
                winner=i;
            }
            else if(submit==p[i][1]){
                if(lasttime>p[i][2]){
                    winner=i;
                }
            }
        }
    }
    printf("%d",winner+1);

}
