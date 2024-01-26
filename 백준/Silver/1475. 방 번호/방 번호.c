#include <stdio.h>

void fill(int* a){
    for(int i=0;i<10;i++){
        a[i]++;
    }
    a[6]++; a[9]++;
}
int main() {
    int n; //다솜이 방 번호
    scanf("%d", &n);
    int set[10] = {};
    int count = 1; //세트 개수

    fill(set); //세트 채우기

    while (1) {
        if (n % 10 == 6 || n % 10 == 9) {
            if(set[n%10]==0){
                fill(set);
                count++;
            }
            set[6]--; set[9]--;

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