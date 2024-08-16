#include <iostream>
using namespace std;

int c=0;

int n,m;

char s[1000001];

int p[1000001]={};

int maxCount=0;

void find_pn(){
    int count=0;

    while(c+2 < m){
        if(s[c]=='I' && s[c+1]=='O' && s[c+2]=='I'){
            count++;
            c+=2;
        }

        else{
            if(count>0){
                p[count]++;
                if(count > maxCount)
                    maxCount=count;
            }

            c++;
            return;
        }
    }

    if(count >0){
        p[count]++;
        if(count > maxCount)
            maxCount=count;
    }

    c=m;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m;

    for(int i=0;i<m;i++){
        cin >> s[i];

    }

    while(c<m){
        if(s[c]=='I')
            find_pn();
        else
            c++;
    }

    int result=0;

    for(int i=n;i<=maxCount;i++){
        if(p[i]){
            result += ((i-n+1) * p[i]);
        }
    }

    cout << result;

}
