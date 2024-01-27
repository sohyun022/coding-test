#include <stdio.h>
#include <stdlib.h>

struct coord{
    int x;
    int y;
};
int compare(const void*a,const void *b){
    if((*(struct coord*)a).y>(*(struct coord*)b).y) return 1;

    else if((*(struct coord*)a).y==(*(struct coord*)b).y){
        if((*(struct coord*)a).x>(*(struct coord*)b).x)
            return 1;
        else return -1;
    }

    else return -1;
}
int main() {
    int n;
    scanf("%d",&n);
    struct coord crd[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&crd[i].x,&crd[i].y);
    }
    qsort(crd,n,sizeof(struct coord),compare);

    for(int i=0;i<n;i++){
        printf("%d %d\n",crd[i].x,crd[i].y);
    }




}