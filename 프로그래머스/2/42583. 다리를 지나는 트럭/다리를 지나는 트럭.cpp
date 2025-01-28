#include <string>
#include <vector>
#include <queue>

//최대트럭개수 bridge_length=다리의 길이, 최대하중 weight ,트럭별 무게 truck_weights

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    int cur_w=0;
    int cur_time=0;
    queue<pair<int,int>> q; //다리 위에 있는 트럭
    int i=0;
    
    while(!q.empty() || i < truck_weights.size()){
        
        cur_time++;  
        
        //트럭을 다리에서 제거
        if(!q.empty() && q.front().second + bridge_length <= cur_time ){ 
            cur_w-=q.front().first; //현재 다리의 하중 감소
            q.pop();
        }
        
        //트럭을 다리에 추가
        if(i < truck_weights.size() && cur_w + truck_weights[i] <= weight && q.size() < bridge_length ){  
            q.emplace(truck_weights[i],cur_time); //트럭의 무게와 진입 시간을 저장
            cur_w+=truck_weights[i]; //현재 다리 하중 증가
 
            i++; //다음 트럭 처리
        }
             
    }
 
    return cur_time;
}