#include <iostream>
#include <vector>

using namespace std;

int cnt=0;

int n,k;

void merge(vector<int>& A,int left,int middle,int right){
    int i=left; //첫 번째 부분 배열의 인덱스
    int j=middle+1; //두 번째 부분 배열의 인덱스
    int t=0; //tmp 배열의 인덱스

    vector<int> tmp(right-left+1);

    while(i <= middle && j <= right){
        if(A[i] <= A[j]){
            tmp[t++] = A[i++];
        }
        else{
            tmp[t++] = A[j++];
        }
    }

    while(i <= middle){
        tmp[t++] = A[i++];
    }

    while(j <= right){
        tmp[t++] = A[j++];
    }

    for(int l=left;l<=right;l++){
        A[l]=tmp[l-left];
        cnt++;
        if(cnt == k) {
            cout << A[l];
            return;
        }
    }
}

void merge_sort(vector<int>& A, int left, int right){
    if(left <right){
        int middle=(left+right)/2;
        merge_sort(A,left,middle);
        merge_sort(A,middle+1,right);
        merge(A,left,middle,right);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    vector<int> A(n);

    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    merge_sort(A,0,n-1);

    if(cnt<k)
        cout << "-1";

}