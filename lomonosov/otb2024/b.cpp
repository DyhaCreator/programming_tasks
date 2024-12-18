#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<pair<int, int>> srt(n);
    for (int i = 0; i < n; i++)
        srt[i] = {a[i], i};
    sort(srt.rbegin(), srt.rend());
    int ans = 0;
    vector<int> used(n);
    for (int i = 0; i < n; i++) {
        if (srt[i].second == i)
            used[i] = 1;
        if (used[i] == 0) {
            int index = i;
            do {
                ans++;
                used[index] = 1;
                index = srt[index].second;
            } while (index != i);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}