#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sequence;
vector<int> numbers;

int visited[8]={};

int n,m;

void recur(int depth){

    if(depth==m){
        for(int i=0;i<m;i++){
            cout << sequence[i] <<" ";
        }
        cout << endl;
        return;
    }

    int recent=0;

    for(int i=0;i<n;i++){
        if(!visited[i] && recent != numbers[i]){
            recent=numbers[i];
            sequence[depth]=numbers[i];
            visited[i]=1;
            recur(depth+1);
            visited[i]=0;
        }
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    numbers.resize(n,0);
    sequence.resize(m,0);

    for(int i=0;i<n;i++){
        cin >> numbers[i];
    }

    sort(numbers.begin(),numbers.end());

    recur(0);

    return 0;
}
