#include<stdio.h>

int stack[100001]={};
int top=-1;
int arr[100001]={};
char push_pop[200001]={};

int main(){
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int idx=0;
    int i=1;
    int cnt=0;

    while(1){
        if(top==-1 || arr[idx]>stack[top]){
            stack[++top]= i++;
            push_pop[cnt++]='+';
        }
        else if(arr[idx] == stack[top]){
            stack[top--]=0;
            push_pop[cnt++]='-';
            idx++;
        }
        else if(arr[idx]<stack[top]){
            printf("NO");
            return 0;
        }

        if(cnt==2*n) break;


    }
    for(int j=0;j<cnt;j++){
        printf("%c\n",push_pop[j]);
    }
}
