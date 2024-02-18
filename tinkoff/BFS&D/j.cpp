#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define ll long long
#define INF 1000000007
using namespace std;

int f(string &num, int k) {
    int ans = 0;
    for (int i = 0; i < num.size(); i++) {
        ans = ((ans * 10) + (num[i] - '0')) % k;
    }
    return ans;
}

int main() {
    string num;
    int k;
    cin >> num >> k;
    int dsize;
    cin >> dsize;
    vector<int> d(dsize);
    for (auto &x : d)
        cin >> x;
    
    sort(d.begin(), d.end());

    queue<string> q;
    q.push(num);

    int col = 0;

    while (!q.empty()) {
        col++;
        string index = q.front();
        // cout << index << endl;
        q.pop();

        if (f(index, k) == 0) {
            cout << index << endl;
            return 0;
        }

        for (auto &x : d) {
            string newNum = index;
            newNum.push_back(x + '0');
            q.push(newNum);
        }
        if (col > 1000000) {
            cout << -1 << endl;
            return 0;
        }
    }

    return 0;
}