#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define INF 1000000007
using namespace std;

vector<vector<ll>> g(10000);

inline int p1r(int a) {
    if (a % 10 != 1) return a - 1;
    return a;
}
inline int p1l(int a) {
    if (a / 1000 != 9) return a + 1000;
    return a;
}
inline int left(int a) {
    return (a * 10) % 10000 + (a / 1000);
}
inline int right(int a) {
    return a / 10 + (a % 10) * 1000;
}

int main() {
    int a, b;
    cin >> a >> b;
    int start = a;
    int step = 0;
    vector<int> visited(10000, INF);
    vector<int> prev(10000, INF);
    queue<int> q;

    q.push(start);
    visited[start] = step;
    prev[start] = -1;
    
    while (!q.empty()) {
        int index = q.front();
        q.pop();

        if (visited[p1l(index)] == INF) {
            q.push(p1l(index));
            visited[p1l(index)] = visited[index] + 1;
            prev[p1l(index)] = index;
        }
        if (visited[p1r(index)] == INF) {
            q.push(p1r(index));
            visited[p1r(index)] = visited[index] + 1;
            prev[p1r(index)] = index;
        }
        if (visited[right(index)] == INF) {
            q.push(right(index));
            visited[right(index)] = visited[index] + 1;
            prev[right(index)] = index;
        }
        if (visited[left(index)] == INF) {
            q.push(left(index));
            visited[left(index)] = visited[index] + 1;
            prev[left(index)] = index;
        }
    }
    cout << visited[b] + 1 << endl;
    int p = b;
    vector<int> ans = {};
    while (p != -1) {
        ans.push_back(p);
        p = prev[p];
    }
    reverse(ans.begin(), ans.end());
    for (auto &x : ans)
        cout << x << endl;
    return 0;
}