#include <iostream>
#include <algorithm>
using namespace std;

void p_search(const int *string,int k,int n){

    long left=1;
    long right=string[k-1];
    long max=0;


    while(left<=right){
        long count=0;
        long length=(left+right)/2;

        for(int i=0;i<k;i++){
            count+= string[i]/length;
        }

        if(count >= n) {
            if(max<length)
                max= length;
            left = length +1;
        }    
        
        else
            right= length-1;

    }
    cout << max;

}

int main() {
    int k,n;
    cin >> k >> n;
    int string[k];

    for(int i=0;i<k;i++){
        cin >> string[i];
    }

    sort(string,string+k);

    p_search(string,k,n);

}
