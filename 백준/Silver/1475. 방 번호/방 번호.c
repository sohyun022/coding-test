#include <stdio.h>

void fill(int* a){
    for(int i=0;i<10;i++){
        a[i]++;
    }
}
int main() {
    int n; //다솜이 방 번호
    scanf("%d", &n);
    int set[10] = {};
    int count = 1; //세트 개수

    fill(set); //세트 채우기

    while (1) {
        if (n % 10 == 6 || n % 10 == 9) {
            if (n % 10 == 6 && set[6] == 0) {
                if (set[9] != 0) set[9]--;
                else {
                    fill(set);
                    count++;
                    set[6]--;
                }
            }

            else if (n % 10 == 9 && set[9] == 0) {
                if (set[6] != 0) set[6]--;
                else {
                    fill(set);
                    count++;
                    set[9]--;
                }
            }
            else
                set[n%10]--;
        }

        else {
            if (set[n % 10] != 0) {
                set[n % 10]--;
            }
            else{
                fill(set);
                count++;
                set[n % 10]--;
            }
        }
        if(n/10==0) break;
        n/=10;
    }
    printf("%d",count);
}
