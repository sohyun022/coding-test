#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i = 0 ;i < schedules.size() ; i++){
        
        bool flag =true;
        
        int  arrival;
        
        if( schedules[i] % 100 >= 50 ){ 
            arrival = schedules[i] + 50;
        }
        else
            arrival = schedules[i] + 10;
        
        for(int j =0 ; j < 7 ;j++){
            if( (startday + j)%7 ==0 || (startday + j)%7 == 6)
                continue;
            else{
    
                if(timelogs[i][j] > arrival){
                    flag= false;
                }
                else{
                    cout << i << "번 직원이 " << j << "번째 날에 출근에 성공"<< endl;
                }
                    
            }  
        
        }
        
        if(flag ==true) answer++;
             
    }
    
    return answer;
}