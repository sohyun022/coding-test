#include <iostream>

using namespace std;

int main(){
    int price;
    cin >> price;

    int remain=1000-price;

    int coin[]={500,100,50,10,5,1};

    int count=0;

    for(int c: coin){

        if(remain/c>0){
            count+=remain/c;
            remain%=c;
        }

        if(remain==0){
            cout << count;
            break;
        }
    }

}
