#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}

int main() {
    int n;

    scanf("%d",&n);

    int a[n];

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    qsort(a,n,sizeof(int),compare);


    int *hash_p;
    int *hash_n;
    if(a[0]<0&&a[n-1]>0){
        hash_p=(int*)calloc((10000001),sizeof(int));
        hash_n=(int*)calloc((10000001),sizeof(int));
    }
    else if(a[0]>=0)
        hash_p=(int*)calloc((a[n-1]+1),sizeof(int));
    else if(a[n-1]<0)
        hash_n=(int*)calloc((-a[0]),sizeof(int));



    for(int i=0;i<n;i++){
        if(a[i]<0)
            hash_n[-a[i]]++;
        else
            hash_p[a[i]]++;
    }

    int m;
    scanf("%d",&m);
    int b[m];
    int k[m];

    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
        if(b[i]<0&&b[i]>=a[0])
            k[i]=hash_n[-b[i]];

        else if(b[i]>=0&&b[i]<=a[n-1])
            k[i]=hash_p[b[i]];

        else
            k[i]=0;

    }
    for(int i=0;i<m;i++){
        printf("%d ",k[i]);
    }
}

