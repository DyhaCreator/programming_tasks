#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int n = 5, x = 0;
vector<int> a;

void solve() {
    int index = n - 1;
    while (index > 0 && a[index] > a[index - 1]) index--;
    int ans = 0;
    for (int i = 0; i < index; i++) {
        if (a[i] > x) {
            int buff = x;
            x = a[i];
            a[i] = buff;
            ans++;
        }
    }

    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            cout << -1 << endl;
            return;
        }
    }

    cout << ans << endl;
}

int main() {
    int t = 10;
    for (int i = 0; i < t; i++) {
        a = {};
        for (int i = 0; i < n; i++) {
            a.push_back(rand() % 20);
        }
    }
    return 0;
}