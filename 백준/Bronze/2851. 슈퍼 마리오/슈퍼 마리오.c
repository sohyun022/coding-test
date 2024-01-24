#include <stdio.h>

int main() {
    int mushroom[10];
    int sum=0;

    for(int i=0;i<10;i++){
        scanf("%d",&mushroom[i]);
    }
    for(int i=0;i<10;i++){
        sum+=mushroom[i];

        if(sum<=100&&(sum+mushroom[i+1])>100) {
            if (100 - sum < sum+mushroom[i + 1] - 100) {
                printf("%d", sum);
                break;
            }
            else{
                printf("%d", sum+mushroom[i+1]);
                break;
            }
        }



    }

    return 0;
}