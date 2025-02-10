#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a = {};
    for (auto &x : s)
        a.push_back(x - '0');
    vector<int> prime = {2, 3, 5, 7};
    vector<int> cnt(4);
    for (auto &x : a) {
        for (int i = 2; i <= x; i++) {
            int l = i;
            for (int j = 0; j < 4; j++) {
                while (l % prime[j] == 0) { 
                    cnt[j]++;
                    l /= prime[j];
                }
            }
        }
    }
    vector<int> b = {};
    while (cnt[3] > 0) {
        b.push_back(7);
        cnt[3]--;
        cnt[2]--;
        cnt[1] -= 2;
        cnt[0] -= 4;
    }
    while (cnt[2] > 0) {
        b.push_back(5);
        cnt[2]--;
        cnt[1]--;
        cnt[0] -= 3;
    }
    while (cnt[1] > 0) {
        b.push_back(3);
        cnt[1]--;
        cnt[0]--;
    }
    while (cnt[0] > 0) {
        b.push_back(2);
        cnt[0]--;
    }
    sort(b.rbegin(), b.rend());
    for (auto &x : b)
        cout << x;
    cout << endl;
    return 0;
}