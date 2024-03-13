#include <stdio.h>
int main() {

    while(1){
        char str[101]="";
        gets(str);

//        printf("%s",str);

        char stack[101]={};
        int top=-1;

        if(str[0]=='.'){
            break;
        }

        int i=0;

        while(1){

//            printf("%c ",str[i]);

            if(str[i]=='.'){
                if(top==-1)
                    printf("yes\n");
                else
                    printf("no\n");
                break;
            }

            if(str[i]=='(' || str[i]=='['){
                stack[++top]=str[i];
            }
            else if(str[i]==')'){
                if(top >= 0 && stack[top]=='(')
                    stack[top--]=0;
                else{
                    printf("no\n");
                    break;
                }
            }
            else if(str[i]==']'){
                if(top >= 0 && stack[top]=='[')
                    stack[top--]=0;
                else{
                    printf("no\n");
                    break;
                }
            }

            i++;
        }

    }

}