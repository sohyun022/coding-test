#include <stdio.h>

int main() {
    char par[51];
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){

        scanf("%s",par);

        int stack[51]={};
        int point=-1;
        int flag=1;

        for(int j=0;par[j]!='\0';j++){
            if(par[j]=='(') {
                point++;
                stack[point] = 1;
            }
            else {
                if (point == -1||stack[point] == 0) {
                    flag=0;
                    break;
                }
                else{
                    stack[point]=0;
                    point--;
                }

            }
        }
        if(point!=-1 && stack[point]!=0)
            flag=0;

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}