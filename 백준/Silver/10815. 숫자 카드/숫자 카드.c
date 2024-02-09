#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b) {
    return *(int *) a - *(int *) b;
}
int bs(const int sorted[],int n,int key){
    int left=0;
    int right=n-1;
    int mid;

    while(left<=right){
        mid=(left+right)/2;
        
        if(sorted[mid]==key)
            return 1;

        if(sorted[mid]<key)
            left=mid+1;
        else
            right=mid-1;
    }
    return 0;
}
int main() {
    int n;
    scanf("%d", &n);
    int card[n];

    for(int i=0;i<n;i++){
        scanf("%d",&card[i]);
    }

    qsort(card,n,sizeof(int),compare);

    int m;
    scanf("%d",&m);
    int num;

    for(int i=0;i<m;i++){
        scanf("%d",&num);
        printf("%d ",bs(card,n,num));
    }
}