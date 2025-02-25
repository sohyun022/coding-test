#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int height = triangle.size();
    int width = triangle[height-1].size();
    
     int dp[height][width];
    
    for(int j=0;j<width;j++){
        dp[height-1][j]=triangle[height-1][j];
    }
    
    for(int i =height-2;i>=0;i--){
        for(int j=0;j<triangle[i].size();j++){
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
        } 
    }
    
    return dp[0][0];
}