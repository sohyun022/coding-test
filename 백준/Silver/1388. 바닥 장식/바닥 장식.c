#include <stdio.h>

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    char floor[52][52]={};

    for(int i=0;i<n;i++){
        scanf("%s",floor[i]);
    }
    int count=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(floor[i][j]=='-'){
                if(floor[i][j+1]!='-')
                   count++;
            }
            else if(floor[i][j]=='|'){
                if(floor[i+1][j]!='|')
                    count++;
            }
        }
    }

    printf("%d",count);

}