#include <stdio.h>

long long city[100001],road[100000]={};

int main() {
    int n;
    scanf("%d",&n);
    long long cost=0;

    for(int i=0;i<n-1;i++){
        scanf("%lld",&road[i]);
    }

    for(int i=0;i<n;i++){
        scanf("%lld",&city[i]);
    }

    long long min=city[0];

    for(int i=0;i<=n;i++){
        if(city[i]<min)
            min=city[i];
        cost+=min*road[i];
    }

    printf("%lld",cost);
    
}