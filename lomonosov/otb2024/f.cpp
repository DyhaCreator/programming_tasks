#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int rec(ll n) {
    if (n == 1) return 1;
    ll y = 0;
    while ((1LL << y) < n)
        y++;
    if (n == (1LL << y)) return 4;
    y--;
    int ans = rec((1LL << y) - (n - (1LL << y))) + 1;
    if (ans == 5) ans = 1;
    return ans;
}

int main() {
    setlocale(0, "");
    ll n, k;
    cin >> n >> k;
    string mp = "ВДКТ";
    int ans = rec(k + 1);
    if (ans == 1) {
        cout << "В" << endl;
    } else if (ans == 2) {
        cout << "Д" << endl;
    } else if (ans == 3) {
        cout << "К" << endl;
    } else if (ans == 4) {
        cout << "Т" << endl;
    }
    return 0;
}