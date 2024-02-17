#include <stdio.h>

int main(){
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

        int n;
        scanf("%d",&n);

        int count=0;

        for(int j=0;j<n;j++){
            int cx,cy,r;
            scanf("%d %d %d",&cx,&cy,&r);

            if((x1-cx)*(x1-cx)+(y1-cy)*(y1-cy)<r*r
             &&(x2-cx)*(x2-cx)+(y2-cy)*(y2-cy)>r*r)
                count++;
            if((x2-cx)*(x2-cx)+(y2-cy)*(y2-cy)<r*r
                &&(x1-cx)*(x1-cx)+(y1-cy)*(y1-cy)>r*r)
                count++;
        }
        printf("%d\n",count);

    }
}