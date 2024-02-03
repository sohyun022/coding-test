#include <stdio.h>

int main() {
    int x;
    scanf("%d",&x);
    int count=0;
    int yeonsan[x+1];
    yeonsan[1]=0;
    yeonsan[2]=1;
    yeonsan[3]=1;

    if(x>3){
        for(int i=4;i<=x;i++) {
            int temp=i;
            count=0;
            if(i % 3==0 && i % 2==0){
                if(yeonsan[i/3]<yeonsan[i/2])
                    temp /= 3;
                else
                    temp /= 2;
            }
            else if (i % 2 == 0) {
                if(yeonsan[i/2]<yeonsan[i-1])
                    temp /= 2;
                else
                    temp -= 1;
            }

            else if (i % 3 == 0) {
                if(yeonsan[i/3]<yeonsan[i-1])
                    temp /= 3;
                else
                    temp -= 1;
            }

            else
                temp -= 1;

            count++;
            count+=yeonsan[temp];
            yeonsan[i] = count;
        }
    }
    printf("%d",yeonsan[x]);

}