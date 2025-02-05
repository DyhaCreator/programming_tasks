#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (auto &x : a)
        if (x > 'Z') x -= 32;
    for (auto &x : b)
        if (x > 'Z') x -= 32;
    vector<int> cnt(26);
    for (auto &x : a)
        if (x >= 'A' && x <= 'Z') cnt[x - 'A']++;
    for (auto &x : b) {
        if (x >= 'A' && x <= 'Z') cnt[x - 'A']--;
        if (x >= 'A' && x <= 'Z' && cnt[x - 'A'] < 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}