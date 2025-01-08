#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums){
    
    set<int> ps(nums.begin(),nums.end());
    return min(ps.size(),nums.size()/2);
  
}