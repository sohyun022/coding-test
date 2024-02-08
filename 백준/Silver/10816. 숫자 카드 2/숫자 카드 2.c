#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;

    scanf("%d",&n);

    int a[500000];

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int *hash_p=(int*)calloc(10000001,sizeof(int));
    int *hash_n=(int*)calloc(10000001,sizeof(int));

    for(int i=0;i<n;i++){
        if(a[i]<0)
            hash_n[-a[i]]++;
        else
            hash_p[a[i]]++;
    }

    int m;
    scanf("%d",&m);
    int b[500000];
    int k[500000];

    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
        if(b[i]<0&&b[i]>=-10000000)
            k[i]=hash_n[-b[i]];

        else if(b[i]>=0&&b[i]<=10000000)
            k[i]=hash_p[b[i]];

    }
    for(int i=0;i<m;i++){
        printf("%d ",k[i]);
    }


    free(hash_p);
    free(hash_n);
}