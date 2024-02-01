#include <stdio.h>
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    int yose[n+1];


    for(int i=1;i<=n;i++){
        yose[i]=i;
    }

    int count=0;
    int cnt=n;
    printf("<");
    while(1) {
        for (int i = 1; i <= n; i++) {
            if (yose[i] != 0){
                count++;
                if (count % k == 0) {
                    printf("%d", yose[i]);
                    yose[i] = 0;
                    cnt--;
                    if(cnt!=0)
                        printf(", ");
                    else
                        break;
                }
            }
        }
        if (cnt == 0){
            printf(">");
            break;
        }


    }

}