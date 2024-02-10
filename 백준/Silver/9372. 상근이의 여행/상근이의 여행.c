#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    
    for(int i=0;i<t;i++){
        int n,m;
        scanf("%d %d",&n,&m);
        int edge[m][2];
        for(int i=0;i<m;i++){
            scanf("%d %d",&edge[i][0],&edge[i][1]);
        }
        printf("%d\n",n-1);
    }
}