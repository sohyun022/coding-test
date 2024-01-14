#include <stdio.h>

int main() {
  long long n;
  scanf("%lld",&n);
  long long sum=1;
  long count=0;

  while(1){
      sum+=6*count;
      if(sum>=n)
          break;
      count++;
  }

  printf("%ld",count+1);
}