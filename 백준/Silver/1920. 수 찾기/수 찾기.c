#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b){
   if(*(long *)a>*(long *)b)
       return 1;
   else
       return 0;
}
int bianary_search(long arr[],int n,long key){
    int start,mid,end;
    start=0;
    end=n-1;

    while(start<=end){
        mid=(start+end)/2;
        if(key==arr[mid]){
            return 1;
        }
        else if(key<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }

    }
    return 0;
}
int main() {
    int n;
    scanf("%d",&n);
    long a[n];
    for(int i=0;i<n;i++){
        scanf("%ld",&a[i]);
    }

    int m;
    scanf("%d",&m);
    long b[m];
    for(int i=0;i<m;i++){
        scanf("%ld",&b[i]);
    }

    qsort(a,n,sizeof(long),compare);

    for(int i=0;i<m;i++){
        printf("%d\n",(bianary_search(a,n,b[i])));
    }
}

