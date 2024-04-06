#include <iostream>
#include <string>

using namespace std;

void add(int x,int& s){
    s |= (1<<x);
}
void remove(int x, int& s){
    s &= ~(1<<x);
}
int check(int x,int& s){
    if(s & (1<<x)){
        return 1;
    }
    else{
        return 0;
    }
}
void toggle(int x,int& s){
    if(check(x,s)==1){
        remove(x,s);
    }
    else
        add(x,s);
}
void all(int& s){
    s |= (1<<21) -1;
}
void empty(int& s){
    s=0;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);


    int s=0;

    int m;
    cin >> m;

    string statement;
    int x;

    for(int i=0;i<m;i++){
        cin >> statement;

        if(statement=="add"){
            cin >> x;
            add(x,s);
        }

        else if(statement=="remove"){
            cin >> x;
            remove(x,s);
        }

        else if(statement=="check"){
            cin >> x;
            cout << check(x,s) << "\n";

        }

        else if(statement=="toggle"){
            cin >> x;
            toggle(x,s);

        }

        else if(statement=="all"){
            all(s);
        }

        else if(statement=="empty"){
            empty(s);

        }

    }

}
