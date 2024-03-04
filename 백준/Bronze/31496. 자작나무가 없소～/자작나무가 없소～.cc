#include <stdio.h>
#include <string.h>
struct Item{
    char name[51];
    int c;
};
struct Item item[100001];

int main(){
    int n;
    scanf("%d",&n);

    char s[51]={};
    scanf("%s",s);

    int count=0;

    for(int i=0;i<n;i++) {
        scanf("%s", item[i].name);
        scanf("%d", &item[i].c);

        char *result =strtok(item[i].name,"_");

        while (result) {

            if(strcmp(result,s)==0){
                count+=item[i].c;
                break;
            }
          //  printf("%s",result);
            result = strtok(NULL,"_");

        }
        /*if(strcmp(result,s)==0){
            count+=item[i].c;
        }*/
    }
    printf("%d",count);
}