#include <stdio.h>
int main()

{
int hour,min,sec,time;
scanf("%d %d %d\n%d",&hour,&min,&sec,&time);

min+=(sec+time)/60;
sec=(sec+time)%60;
hour+=min/60;
min%=60;
hour%=24;


printf("%d %d %d",hour,min,sec);
return 0;
}
