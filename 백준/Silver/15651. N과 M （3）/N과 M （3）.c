#include <stdio.h>
int n,m;
int sequence[7]={};

void MkSeq(int depth){
    if(depth==m){
        for(int i=0;i<m;i++){
            printf("%d ",sequence[i]);
        }
        printf("\n");
        return;
    }

    for(int i=1;i<=n;i++){
        sequence[depth]=i;
        MkSeq(depth+1);
    }

}
int main(){

    scanf("%d %d",&n,&m);

    MkSeq(0);
    
}