#include <string>
#include <vector>

using namespace std;

int answer=0;
int t;
int length;

void solve(vector<int> nums,int index,int sum){
    
    if(index==length){ //인덱스가 배열의 길이와 같아지면(=모든 수를 사용했다는 의미)
        if(sum==t) //sum이 target값과 같으면
            answer++; 
        return;
    }
    
    solve(nums,index+1,sum+nums[index]); //현재 인덱스의 값을 더함
    solve(nums,index+1,sum-nums[index]);  //현재 인덱스의 값을 뺌
    
}

int solution(vector<int> numbers, int target) {
    t = target; //dfs 함수에서 사용할 타겟 값을 넘겨줌
    length = numbers.size(); //dfs 함수에서 종료조건(깊이)
    solve(numbers,0,0); //깊이:0, 합:0에서 시작
    
    return answer;
}

