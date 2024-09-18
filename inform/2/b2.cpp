#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (auto &x : a) {
        cin >> x;
        if (x == -1) ans++;
    }
    cout << ans << endl;
    ans = 0;
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 || visited[i] == 1) {
            visited[i] = 1;
            continue;
        }
        int index = i;
        int find = 0;
        while (a[index] != -1) {
            visited[index] = 1;
            if (a[index] - 1 - index != 1)
                find = 1;
            index = a[index] - 1;
        }
        ans += find;
        /*for (auto &x : visited)
            cout << x << " ";
        cout << endl;*/
    }
    cout << ans << endl;
    return 0;
}