#include <stdio.h>

struct people{
    int x;
    int y;
    
};

int main(){
    int n;
    scanf("%d",&n);

    struct people p[n];


    for(int i=0;i<n;i++){
        scanf("%d %d",&p[i].x,&p[i].y);
    }
    int count=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(p[i].x < p[j].x && p[i].y < p[j].y)
                count++;
        }
        printf("%d ",count+1);
        count=0;


    }


}
