#include <stdio.h>
#include <math.h>

int main(){
    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);

    if(b>=c) printf("-1");
    else
        if(a/(c-b)==ceil(a/(c-b)))
            printf("%.f",ceil(a/(c-b))+1);
        else
            printf("%.f",ceil(a/(c-b)));

}