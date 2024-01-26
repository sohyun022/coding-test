#include <stdio.h>
#include <string.h>
void fill(int* a){
    for(int i=0;i<10;i++){
        a[i]++;
    }
    a[6]++; a[9]++;
}
int main() {
    char n[8]; //다솜이 방 번호
    scanf("%s", n);
    int set[10] = {};
    int count = 1; //세트 개수
    fill(set); //세트 채우기
    int l=strlen(n);

    for(int i=0;i<l;i++){
        if(set[n[i]-'0']==0){
            fill(set);
            count++;
        }

        if(n[i]=='6'||n[i]=='9'){
            set[6]--;
            set[9]--;
        }
        else
            set[n[i]-'0']--;
    }
    printf("%d",count);
}
