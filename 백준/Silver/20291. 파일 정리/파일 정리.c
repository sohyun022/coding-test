#include<stdio.h>
#include <string.h>
#include <stdlib.h>
char file[50000][101];
typedef struct {
    char extension[101];
}ext;

typedef struct {
    char Ext[101];
    int cnt;
}result;
int compare(const void *a,const void *b){
    if(strcmp(((ext *)a)->extension,((ext *)b)->extension)>0)
        return 1;
    else return -1;
}
int main(){
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%s",file[i]);
    }

    ext E[n];

    for(int i=0;i<n;i++){
        char *ptr=strchr(file[i],'.');
        strcpy(E[i].extension,ptr+1);
    }

    qsort(E,n,sizeof(ext),compare);

//    for(int i=0;i<n;i++){
//        printf("%s\n",E[i].extension);
//    }

    int count=1;

    char *tmp;

    int k=0;

    result answer[n];

    for(int i=1;i<n;i++){
        tmp=E[i-1].extension;

        if(strcmp(tmp,E[i].extension)==0)
            count++;
        else {
            strcpy(answer[k].Ext,E[i-1].extension);
            answer[k].cnt=count;
            k++;
            count=1;
        }
    }
    strcpy(answer[k].Ext, E[n - 1].extension);
    answer[k].cnt = count;
    k++;

    for(int i=0;i<k;i++){
        printf("%s %d\n",answer[i].Ext,answer[i].cnt);
    }


}