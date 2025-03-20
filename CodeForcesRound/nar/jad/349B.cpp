#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int v;
    cin >> v;
    vector<int> a(9);
    for (auto &x : a)
        cin >> x;
    
    vector<pair<int, int>> b(9);
    for (int i = 0; i < 9; i++)
        b[i] = {a[i], i};
    sort(b.begin(), b.end());
    if (b[0].F > v) {
        cout << - 1 << endl;
        return 0;
    }
    vector<int> ans = {};
    for (int i = 0; i < v / b[0].F; i++)
        ans.push_back(b[0].S);
    int ost = v % b[0].F;
    for (auto &x : ans) {
        ost += b[0].F;
        int index = 1;
        while (b[index].F <= ost && index < 9)
            index++;
        int mx = 0;
        for (int i = 0; i < index; i++) {
            if (b[i].S > b[mx].S) {
                mx = i;
            }
        }
        ost -= b[mx].F;
        x = b[mx].S;
    }
    for (auto &x : ans)
        cout << x + 1;
    cout << endl;
    return 0;
}