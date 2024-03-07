#include <stdio.h>
#include <string.h>
int main() {
    char string[1000001];

    scanf("%[^\n]s",string);

    int count=0;

    char * result = strtok(string," ");

    while(result != NULL){
        count++;
//        printf("%s\n",result);
        result = strtok(NULL," ");
    }

    printf("%d",count);
}