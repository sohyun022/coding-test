#include <stdio.h>
#include <string.h>
int main() {
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){
        int n;
        char str[21];

        scanf("%d",&n);
        scanf("%s",str);

        for(int j=0;j<strlen(str);j++){
            for(int k=0;k<n;k++){
                printf("%c",str[j]);
            }
        }
        printf("\n");
    }
}