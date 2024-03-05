#include <stdio.h>
#include <stdlib.h>
int comparea(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int compareb(const void *a,const void *b){
    return *(int *)b-*(int *)a;
}
int main() {
    int n;
    scanf("%d",&n);

    int a[100]={};
    int b[100]={};

    int s=0;

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }

    qsort(a,n,sizeof(int),comparea);
    qsort(b,n,sizeof(int),compareb);

    for(int i=0;i<n;i++){
        s+=a[i]*b[i];
    }

    printf("%d",s);
    
}