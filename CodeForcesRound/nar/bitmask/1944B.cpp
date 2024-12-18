#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<int> countA(n + 1);
    vector<int> countB(n + 1);
    for (auto &x : a)
        countA[x]++;
    for (auto &x : b)
        countB[x]++;
    vector<int> ans1 = {};
    vector<int> ans2 = {};

    int index = 0;
    while (index <= n && ans1.size() < 2 * k) {
        if (countA[index] == 2) {
            ans1.push_back(index);
            ans1.push_back(index);
        }
        index++;
    }
    index = 0;
    while (index <= n && ans2.size() < 2 * k) {
        if (countB[index] == 2) {
            ans2.push_back(index);
            ans2.push_back(index);
        }
        index++;
    }

    for (int i = 0; i <= n; i++) {
        if (countA[i] == 1) {
            ans1.push_back(i);
            ans2.push_back(i);
        }
        if (ans1.size() == 2 * k) {
            break;
        }
    }

    for (auto &x : ans1)
        cout << x << " ";
    cout << endl;
    for (auto &x : ans2)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}