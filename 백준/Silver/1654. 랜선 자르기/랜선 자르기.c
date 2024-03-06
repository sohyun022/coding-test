#include <stdio.h>
#include <stdlib.h>
//n개이상 만들어야한다->매개변수k_length[i]

void p_search(const int *k_length,int k,int n){

    long long start=1;
    long long end=k_length[k-1];
    long long length_max=0;

    while(start<=end){
        long long mid=(start+end)/2;

        long long count=0;

        for(int i=0;i<k;i++){
            count += k_length[i] / mid;
        }

        if(count>=n){
           if(length_max<mid)
               length_max=mid;
           start=mid+1;
        }
        else
            end=mid-1;
    }

    printf("%lld",length_max);


}

int compare(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int main() {
    int k;
    int n;

    scanf("%d %d",&k,&n);

    int k_length[10001]={};

    for(int i=0;i<k;i++){
        scanf("%d",&k_length[i]);
    }

    qsort(k_length,k,sizeof(int),compare);
    p_search(k_length,k,n);

}