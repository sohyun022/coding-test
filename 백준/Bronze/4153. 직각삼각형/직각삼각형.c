#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int main() {
    int l[3]={};

    while (1) {
        scanf("%d %d %d", &l[0], &l[1], &l[2]);

        if(l[0]==0&&l[1]==0&&l[2]==0) break;

        qsort(l, 3, sizeof(int), compare);

        if (l[2] * l[2] == l[0] * l[0] + l[1] * l[1])
            printf("right\n");
        else
            printf("wrong\n");


    }
}