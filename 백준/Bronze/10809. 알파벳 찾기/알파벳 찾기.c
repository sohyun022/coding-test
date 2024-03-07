#include <stdio.h>
#include <string.h>
int main() {
    char string[101];

    scanf("%s",string);

    char alphabet='a';

    int flag;

    while(alphabet<='z'){
        flag=0;
        for(int i=0;i<strlen(string);i++){
            if(string[i]==alphabet){
                printf("%d ",i);
                flag=1;
                break;
            }
        }
        if(flag==0) printf("-1 ");
        
        alphabet++;
    }
}