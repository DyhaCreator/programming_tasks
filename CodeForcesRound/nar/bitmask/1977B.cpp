#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
vector<ll> vec = {};
ll n;
int found = 0;

void gen(ll num, int index) {
    /*for (auto &x : vec)
        cout << x << " ";
    cout << endl;*/
    if (num == n) {
        cout << vec.size() << endl;
        for (auto &x : vec)
            cout << x << " ";
        cout << endl;
        found = 1;
        return;
    }
    if (index <= 0)
        return;
    if (num > n) {
        for (int i = 0; i < index - 1; i++) {
            vec[i] = -1;
            if (num - (1 << (i + 1)) <= n || num - (1 << i) <= n)
                gen(num - (1 << i), i);
            vec[i] = 0;
        }
    } else {
        for (int i = 0; i < index - 1; i++) {
            vec[i] = 1;
            if (num + (1 << (i + 1)) >= n || num + (1 << i) >= n) 
                gen(num + (1 << i), i);
            vec[i] = 0;
        }
    }
}


void solve() {
    cin >> n;
    ll num = 0;
    while ((1 << num) <= n * 2) {
        vec.push_back(1);
        if ((1 << (num + 1)) >= n || (1 << num) >= n)
            gen((1 << num), num);
        vec[vec.size() - 1] = 0;
        if (found) break;
        num++;
    }
    found = 0;
    vec = {};
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}