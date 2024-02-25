#include<stdio.h>
int enjoy=0;
int find_enjoy(int n){
    if(n==0 || n==1) return 1;
    else{
        enjoy += n/2 * (n-n/2);
        find_enjoy(n/2);
        find_enjoy(n-n/2);
    }
}
int main(){
    int n;
    scanf("%d",&n);

    find_enjoy(n);

    printf("%d",enjoy);
}

