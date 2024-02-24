#include<stdio.h>
int matrix[1001][1001]={};
int visited1[1001]={};
int visited2[1001]={};

void dfs(int v,int n){ //stack
    int stack[1001]={};
    int top=1;
    int empty;
    int tmp;

    stack[top]=v;
    visited2[v]=1;
    printf("%d ",v);

    while(top){
        empty=1;
        tmp=stack[top];

        for(int i=1;i<=n;i++){
            if(matrix[tmp][i] && !visited2[i]){
                stack[++top]=i;
                visited2[i]=1;
                empty=0;
                printf("%d ",i);
                break;
            }
        }

        if(empty)
            top--;

    }

    printf("\n");

}

void bfs(int v,int n){ //queue
    int queue[1001]={};
    int front=0,rear=0;
    int tmp;
    queue[++rear]=v;
    visited1[v]=1;
    printf("%d ",v);

    while(front!=rear){
        tmp=queue[front+1];
        front++;
        for(int i=1;i<=n;i++){
            if(matrix[tmp][i] && !visited1[i]){
                printf("%d ",i);
                visited1[i]=1;
                queue[++rear]=i;
            }
        }
    }
}
int main(){
    int n,m,v;

    scanf("%d %d %d",&n,&m,&v);

    int a,b;

    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        matrix[a][b]=1;
        matrix[b][a]=1;
    }

    dfs(v,n);
    bfs(v,n);

}
