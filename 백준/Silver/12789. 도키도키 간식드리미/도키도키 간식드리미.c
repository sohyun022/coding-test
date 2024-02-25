#include<stdio.h>
int stack[1001]={};
int top=-1;

int main(){
    int n;
    scanf("%d",&n);

    int student[1001]={};

    for(int i=0;i<n;i++){
        scanf("%d",&student[i]);
    }

    int count=1;
    int i=0;

    while(i<n){

        if(top != -1 && stack[top]==count){ //스택에 있는 학생 번호가 count일 때
            count++;
            stack[top--]=0;
        }
        else if(student[i]==count){ //학생 번호가 count일 때
            count++;
            i++;
        }
        else if(top == -1 || stack[top]>student[i]){ //학생 차례가 아닐때 스택에 넣음
            stack[++top]=student[i];
            i++;
        }

        else{
            printf("Sad");
            return 0;
        }


    }

    printf("Nice");
}
