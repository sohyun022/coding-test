#include <stdio.h>
#include <string.h>
#define MAX 10001

int Deque[MAX]={};

typedef struct {
    int front;
    int rear;
}Dq;

void InitDq(Dq *dq){
    dq->front=0;
    dq->rear=0;
}

int empty(Dq *dq){
    return dq->rear==dq->front;
}

void push_front(Dq *dq,int x){
    Deque[dq->front]=x;
    dq->front=(dq->front-1 + MAX) % MAX;
}
void push_back(Dq *dq,int x){
    dq->rear=(dq->rear+1 + MAX) % MAX;
    Deque[dq->rear]=x;
}
void pop_front(Dq *dq){
    if(!empty(dq)) {
        printf("%d\n", Deque[(dq->front + 1 + MAX) % MAX]);
        Deque[(dq->front + 1 + MAX) % MAX] = 0;
        dq->front=(dq->front + 1 + MAX) % MAX;
    }
    else
        printf("-1\n");
}
void pop_back(Dq *dq){
    if(!empty(dq)) {
        printf("%d\n", Deque[dq->rear]);
        Deque[dq->rear] = 0;
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }
    else
    printf("-1\n");
}
void size(Dq *dq){
    printf("%d\n",(dq->rear+MAX-dq->front+MAX)%MAX);
}

void front(Dq *dq){
    if(!empty(dq))
        printf("%d\n",Deque[(dq->front+1+ MAX) % MAX]);
    else
        printf("-1\n");
}
void back(Dq *dq){
    if(!empty(dq))
        printf("%d\n",Deque[dq->rear]);
    else
        printf("-1\n");
}

int main() {
    char state[20];
    int n;
    scanf("%d",&n);
    Dq dq;
    InitDq(&dq);


    for(int i=0;i<n;i++){

        scanf("%s",state);

        if(strcmp(state,"push_front")==0){
            int x;
            scanf("%d",&x);
            push_front(&dq,x);
        }
        else if(strcmp(state,"push_back")==0){
            int x;
            scanf("%d",&x);
            push_back(&dq,x);
        }
        else if(strcmp(state,"pop_front")==0){
            pop_front(&dq);
        }
        else if(strcmp(state,"pop_back")==0){
            pop_back(&dq);
        }
        else if(strcmp(state,"size")==0){
            size(&dq);
        }
        else if(strcmp(state,"empty")==0){
            printf("%d\n",empty(&dq));
        }
        else if(strcmp(state,"front")==0){
            front(&dq);
        }
        else if(strcmp(state,"back")==0){
            back(&dq);
        }
    }
}