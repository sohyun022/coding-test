#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int count=0;

    int x1,y1,x2,y2,r1,r2;

    for(int i=0;i<n;i++) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        int X=x1-x2;
        int Y=y1-y2;
        int d=(X*X)+(Y*Y);

        if(x1==x2&&y1==y2){
            if(r1!=r2) //좌표는 같고 반지름이 다를 때
                count=0;

            else //두 원이 일치
                count=-1;
        }
        else if(x1!=x2||y1!=y2){


            if((r1+r2)*(r1+r2)==d||(r1-r2)*(r1-r2)==d) //내접 또는 외접
                count=1;
            else if((r1-r2)*(r1-r2)>d||(r1+r2)*(r1+r2)<d) //두 원이 만나지 않을 때,삼각형의 조건
                count=0;
            else //접점이 두 개일 때
                count=2;

        }
        printf("%d\n",count);
    }
}