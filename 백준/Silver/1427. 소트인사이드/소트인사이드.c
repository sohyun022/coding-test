#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b){
    return *(int *)b-*(int *)a;
}
int main() {
    char num[11]={};
    scanf("%s",num);
    int number[11]={};
    int count=0;

    for(int i=0;num[i]!='\0';i++){
        number[i]=num[i]-48;
        count++;
    }

    qsort(number,11,sizeof(int),compare);

    for(int i=0;i<count;i++){
        printf("%d",number[i]);
    }
}