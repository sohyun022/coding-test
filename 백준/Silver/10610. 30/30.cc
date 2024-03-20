#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a,const void *b){
    return *(int *)b-*(int *)a;
}
int main() {

    char numbers[100001]={};
    scanf("%s",numbers);

    unsigned long l= strlen(numbers);

    int num[100001]={};

    for(int i=0;i<l;i++){
        num[i]=numbers[i]-'0';
    }
    int sum=0;

    for(int i=0;i<l;i++){
        sum+=num[i];
    }

    qsort(num,l,sizeof(int),compare);


    if(sum%3==0 && num[l-1]==0){
        for(int i=0;i<l;i++){
            printf("%d",num[i]);
        }
    }
    else
        printf("-1");

}