#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int a, b;
    cin >> a >> b;
    queue<int> q;
    map<int, int> used;
    used[a] = 0;
    q.push(a);
    while (!q.empty()) {
        int num = q.front();
        q.pop();
        if (num <= 10000 && used[num * 2] == 0) {
            q.push(num * 2);
            used[num * 2] = used[num] + 1;
        }
        if (num > 1 && used[num - 1] == 0) {
            q.push(num - 1);
            used[num - 1] = used[num] + 1;
        }
    }
    cout << used[b] << endl;
    return 0;
}