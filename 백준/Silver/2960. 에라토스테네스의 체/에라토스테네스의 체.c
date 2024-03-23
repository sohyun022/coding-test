#include <stdio.h>

int visited[1001]={};

int main() {
    int n,k;
    scanf("%d %d",&n,&k);

    int count=0;
    int i=2;

    while(1){

        for(int j=i;j<=n;j+=i){
            if(!visited[j]){
                visited[j]=1;
                count++;
            }

            if(count==k){
                printf("%d",j);
                return 0;
            }
        }

        i++;

    }
    
}