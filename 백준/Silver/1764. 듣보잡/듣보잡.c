#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct DB{
    char name[21];
};
struct DB N[500000];
struct DB M[500000];
struct DB List[500000];

int count=0;
int compare(const void *a,const void *b){
    a=((struct DB *)a)->name;
    b=((struct DB *)b)->name;

    if(strcmp(a,b)>0) return 1;
    else return -1;
}

int bs(int n,char *key){
    int left=0;
    int right=n-1;
    int middle;

    while(left<=right){
        middle=(left+right)/2;

        if(strcmp(N[middle].name,key)==0){
            strcpy(List[count++].name,key);
            return 0;
        }
        else if(strcmp(N[middle].name,key)>0){
            right=middle-1;
        }
        else
            left=middle+1;
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++){
        scanf("%s",N[i].name);
    }

    for(int i=0;i<m;i++){
        scanf("%s",M[i].name);
    }

    qsort(N,n,sizeof(struct DB),compare);
    qsort(M,m,sizeof(struct DB),compare);

    for(int i=0;i<m;i++){
        bs(n,M[i].name);
    }

    printf("%d\n",count);

    for(int i=0;i<count;i++){
        printf("%s\n",List[i].name);
    }
}