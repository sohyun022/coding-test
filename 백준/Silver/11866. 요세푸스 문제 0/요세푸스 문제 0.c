#include <stdio.h>
int main() {
    int n;
    int k;
    scanf("%d %d",&n,&k);
    int arr[n+1];

    for(int i=0;i<=n;i++){
        arr[i]=i;
    }

    int count=0;
    printf("<");
    int t=1;
    int c=n;

    while(1){
        if(arr[t]!=0){
            count++;

            if(count%k==0) {
                if (t == k){
                    printf("%d", arr[t]);
                    arr[t]=0;
                    c--;


                }
                else{
                    printf(", %d", arr[t]);
                    arr[t]=0;
                    c--;

                }
            }
        }
        if(c==0) break;
        t++;
        if(t>n) t=1;
    }
    printf(">");
}
