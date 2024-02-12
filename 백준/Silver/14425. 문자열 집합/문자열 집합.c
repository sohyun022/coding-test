#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char word[501];
}Strings;

int binary_search(Strings *str,int n,const char *key){
    int left=0;
    int right=n-1;
    int middle;

    while(left<=right){
        middle=(left+right)/2;

        if(strcmp(str[middle].word,key)==0)
            return 1;
        else if(strcmp(str[middle].word,key)>0)
            right=middle-1;
        else
            left=middle+1;
    }
    return 0;
}
int compare(const void *a,const void *b){
    return strcmp(((Strings *)a)->word,((Strings *)b)->word);
}

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    Strings str[n];
    char comparestr[501];

    for(int i=0;i<n;i++){
        scanf("%s",str[i].word);
    }

    qsort(str,n,sizeof(Strings),compare);

    int count=0;

    for(int i=0;i<m;i++){
        scanf("%s",comparestr);
        if(binary_search(str,n,comparestr))
            count++;
    }

    printf("%d",count);


}