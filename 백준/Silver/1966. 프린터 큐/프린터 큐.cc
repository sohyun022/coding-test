#include <iostream>
#include <queue>
using namespace std;

int main(){

    int t;

    cin >> t;

    int n,m;

    int priority;

    for(int i=0;i<t;i++){

        priority_queue <int> q;
        queue <pair<int,int>> printer_q;

        cin >> n;
        cin >> m;
        int count=1;


        for(int j=0;j<n;j++){
            cin >> priority;
            q.push(priority);
            printer_q.emplace(j,priority);
        }

        while(true){

            int tmp1=printer_q.front().second;
            int tmp2=printer_q.front().first;


            if(tmp1==q.top()){
                if(tmp2==m){
                    cout << count << endl;
                    break;
                }
                printer_q.pop();
                q.pop();
                count++;

            }
            else{
                printer_q.emplace(tmp2,tmp1);
                printer_q.pop();

            }

        }

    }

}
