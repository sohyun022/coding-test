#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b){
    return *(int *)b-*(int *)a;
}

int main() {
   int n;
   scanf("%d",&n);

   int rope[100001]={};

   int max=0;

   for(int i=0;i<n;i++){
       scanf("%d",&rope[i]);
   }

   qsort(rope,n,sizeof(int),compare);

   for(int i=0;i<n;i++){
       if(max<=rope[i]*(i+1))
           max=rope[i]*(i+1);
   }

   printf("%d",max);

}