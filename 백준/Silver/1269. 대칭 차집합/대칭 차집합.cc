#include <iostream>
#include <algorithm>
using namespace std;

bool b_search(const int *arr,int n,int key){
    int left = 0;
    int right = n-1;

    while(left<=right){
        int middle = (left+right)/2;

        if(arr[middle]==key) return true;
        else if(arr[middle]<key) left=middle+1;
        else right=middle-1;
    }
    return false;
}
int main() {

    int an,bn;

    cin >> an >> bn;

    int a[200000]={};
    int b[200000]={};

    int count=0;

    for(int i=0;i<an;i++){
        cin >> a[i];
        count++;
    }
    sort(a,a+an);

    for(int i=0;i<bn;i++){
        cin >> b[i];
        if(b_search(a,an,b[i]))
            count--;
        else count++;

    }

    cout << count;

    return 0;
}
