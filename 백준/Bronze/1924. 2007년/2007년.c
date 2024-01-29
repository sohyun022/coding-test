#include <stdio.h>
int main() {
    int x, y, i;
    int sum=0;
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *week[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};

    for(i=0;i<=12;i++){
        sum+=month[i];
    }
    scanf("%d %d", &x, &y);

    sum=0;


    for(i=1;i<x;i++){
        sum+=month[i];
    }

    printf("%s",week[(sum+y)%7]);

}