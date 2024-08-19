#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string emp;
    map<string,int,greater<>> map;

    string status;

    for(int i=0;i<n;i++){
        cin >> emp >> status ;

        if(status=="enter"){
            map[emp]=1;
        }

        else{
            map.erase(emp);
        }

    }
    
    for(const auto& employee: map){
        cout << employee.first<<"\n";
    }
}