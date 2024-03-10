#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a,const void *b){
    return *(int *)a-*(int *)b;

}
int main() {
    int opinion[300000]={};

    int n;
    scanf("%d",&n);

    if(n==0){
        printf("%d",0);
        return 0;
    }


    for(int i=0;i<n;i++){
        scanf("%d",&opinion[i]);
    }

    double a=round((double)n*0.15);

    double sum=0;

    qsort(opinion,n,sizeof(int),compare);

    for(int i=(int)a;i<n-(int)a;i++){
        sum+=opinion[i];
    }

    printf("%.0lf",round(sum/(n-(int)a*2)));
}