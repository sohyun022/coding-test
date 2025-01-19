#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    unordered_map<string, vector<pair<int, int>>> list;
    unordered_map<string,int> maps;
    int n=genres.size();
    vector<int> result;
    
    for(int i=0;i<n;i++){
        list[genres[i]].emplace_back(plays[i],i); //장르별 (재생횟수,고유번호)
        maps[genres[i]]+=plays[i]; //장르별 전체 재생횟수
    }
    
    vector<pair<string,int>> sortedGenres(maps.begin(),maps.end());
    sort(sortedGenres.begin(),sortedGenres.end(),[](const auto& a,const auto&b){
            return a.second > b.second; });
    //장르를 전체 재생횟수 순으로 정렬
    
    for(auto& genre: list){
        sort(genre.second.begin(),genre.second.end(),[](const auto& a,const auto&b){
            if(a.first == b.first){ //재생횟수가 같으면
                return a.second < b.second; //고유번호가 낮은 순으로 정렬
            }
            return a.first > b.first;
        });
    } //각각의 장르에 대해 노래를 재생횟수 순으로 정렬
    
    for(auto genre: sortedGenres){
        if(list[genre.first].size()==1) //장르의 노래 개수가 1인경우
            result.push_back(list[genre.first][0].second); //장르 별 첫번째 순위의 고유번호
        else{
            result.push_back(list[genre.first][0].second);
            result.push_back(list[genre.first][1].second);
            }  
    }

    return result;
}