#include <stdio.h>
#include <stdlib.h>
struct information{
    int age;
    char name[101];
};

int compare(const void *a,const void *b){
    if(((struct information *)a)->age>((struct information *)b)->age)
        return 1;
    else return 0;
}
int main() {

    int n;
    scanf("%d",&n);
    struct information a[n];

    for(int i=0;i<n;i++){
        scanf("%d",&a[i].age);
        scanf("%s",a[i].name);
    }

    qsort(a,n,sizeof(struct information),compare);

    for(int i=0;i<n;i++){
        printf("%d ",a[i].age);
        printf("%s\n",a[i].name);
    }

}