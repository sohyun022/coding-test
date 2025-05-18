#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;

    vector<int> s(n);
    vector<int> d;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    sort(s.begin(), s.end());


    for (int i = 1; i < n; i++)
        d.push_back(s[i] - s[i - 1]);

    sort(d.begin(), d.end(),greater());

    int total = 0;
    for (int i = k - 1; i < d.size(); ++i)
        total += d[i];

    cout << total;

    return 0;
}
