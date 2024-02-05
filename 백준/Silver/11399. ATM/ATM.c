#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b){
    return *(int*)a-*(int*)b;

}
int main() {
    int n;
    scanf("%d",&n);
    int p[n];
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    qsort(p,n,sizeof(int),compare);

    int sum=0;

    for(int i=0;i<n;i++){
        for(int j=n-i;j>=1;j--){
            sum+=p[i];
        }
    }

    printf("%d",sum);


}

