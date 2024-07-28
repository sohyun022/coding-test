#include <iostream>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str[3];
    int index;
    int num;

    int fourth;

    for(int i=0;i<3;i++){
        cin >> str[i];
        if(str[i]!="FizzBuzz" && str[i]!="Fizz" && str[i]!="Buzz"){
            index=i;
            num=stoi(str[i]);
        }
    }

    fourth=num+3-index;

    if(fourth%3==0 && fourth%5==0) cout << "FizzBuzz";
    else if(fourth%3==0 && fourth%5!=0) cout << "Fizz";
    else if(fourth%3!=0 && fourth%5==0) cout << "Buzz";
    else cout << fourth;

    return 0;
}
