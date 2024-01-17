#include <stdio.h>
#include <string.h>
int stack[10000]={};
int top=0;

void Push(int x){
    stack[top]=x;
    top++;
}
void Pop(){
    if(top){
        printf("%d\n",stack[top-1]);
        stack[top-1]=0;
        top--;}

    else printf("-1\n");
}
void Size(){
    printf("%d\n",top);
}
void Empty(){
    if(top)
        printf("0\n");
    else
        printf("1\n");
}
void Top(){
    if(top)
        printf("%d\n",stack[top-1]);
    else
        printf("-1\n");
}


int main() {
int n;
scanf("%d",&n);
char statement[10]={};
int x;
for(int i=0;i<n;i++){

    scanf("%s",statement);

    if(!strcmp(statement,"push")) {
        scanf("%d",&x);
        Push(x);
    }
    else if(!strcmp(statement,"pop")){
        Pop();
    }
    else if(!strcmp(statement,"size")){
        Size();
    }
    else if(!strcmp(statement,"empty")){
        Empty();
    }
    else if(!strcmp(statement,"top")){
        Top();
    }

}



}
