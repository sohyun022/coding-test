#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(int number, int n, int m) {
    int answer = 0;
    
    if(number%n == 0 && number%m == 0)
        answer=1;
    
    return answer;
}

int main(){
    
    int number,n,m;
    cin >> n >> m;
    cout << solution(number,n,m);
    return 0;
    
}