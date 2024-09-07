#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; //테스트 케이스 수
    cin >> t;

    string function;
    int n;

    for(int i =0; i<t;i++){
        cin >> function; //함수

        cin >> n; //배열 길이

        deque<int> dq;

        string nums; //배열

        cin >> nums;

        unsigned int len=nums.size();

        string tmp;

        for(int j=1;j<len;j++){
           if(nums[j]==',' || nums[j]==']'){
               if(!tmp.empty()){
                   dq.push_back(stoi(tmp));
                   tmp="";
               }
           }
           else
               tmp+=nums[j];
        }

        bool front=true;

        bool flag=false;

        for(char f : function){
            if(f=='R'){

                if(front)
                    front=false;
                else
                    front=true;
            }

            else if(f=='D'){

                if(dq.empty()){
                    cout << "error\n";
                    flag=true;
                    break;
                }
                else if(front){
                    dq.pop_front();
                }
                else
                    dq.pop_back();
            }
        }

        if(flag)
            continue;

        else{
            if(!front){
                reverse(dq.begin(), dq.end());
            }

            unsigned int l=dq.size();

            cout << "[";

            for(int k=0;k<l;k++){
                cout << dq.front();
                dq.pop_front();
                if(k!=l-1){
                    cout <<",";
                }
            }

            cout << "]\n";
        }

    }
}