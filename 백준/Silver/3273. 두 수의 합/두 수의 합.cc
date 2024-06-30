#include <iostream>
#include <algorithm>

int compare(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}

using namespace std;

int main() {

    int n,k;

    cin >> n;

    int num[n];

    for(int i=0;i<n;i++){
        cin >> num[i];
    }

    cin >> k;

    qsort(num,n,sizeof(int),compare);

    int left=0;
    int right=n-1;
    int count=0;

    while(left<right && right <= n-1){
        int l=num[left];
        int r=num[right];

        if(l+r==k){
            count++;
            left++;
            right--;
        }
        else if(l+r>k){
            right--;
        }
        else{
            left++;
        }

    }
    cout << count;

}
