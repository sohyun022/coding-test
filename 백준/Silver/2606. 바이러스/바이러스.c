#include <stdio.h>
int visited[101]={};
void bfs(int (*mat)[101],int i,int n){
        if (!visited[i]){
            visited[i]=1;
            for(int j=1;j<=n;j++)
                if(mat[i][j])
                    bfs(mat,j,n);
        }
}
int main() {

    int n;
    scanf("%d",&n);

    int matrix[101][101]={};

    int t;
    scanf("%d",&t);

    int tuple[2];
    for(int i=0;i<t;i++){
        scanf("%d %d",&tuple[0],&tuple[1]);
        matrix[tuple[0]][tuple[1]]=1;
        matrix[tuple[1]][tuple[0]]=1;
    }

    for(int i=1;i<=n;i++){
        if(matrix[1][i]){
            bfs(matrix,i,n);
        }

    }
    int count=0;

    for(int i=2;i<=n;i++){
        if(visited[i])
            count++;
    }
    printf("%d",count);



}