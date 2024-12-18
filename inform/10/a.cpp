#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string s;
    vector<int> count(256);
    while (cin >> s) {
        for (auto &x : s)
            count[x]++;
    }
    string sym = "";
    for (int i = 0; i < 255; i++) {
        if (count[i] > 0) {
            sym.push_back(char(i));
        }
    }
    int mx = 0;
    for (auto &x : sym) mx = max(count[x], mx);
    for (int i = mx; i > 0; i--) {
        for (auto &x : sym) {
            if (count[x] >= i) cout << "#";
            else cout << " ";
        }
        cout << endl;
    }
    cout << sym << endl;
    return 0;
}