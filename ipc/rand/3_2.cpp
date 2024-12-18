#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

ll n;
map<ll, int> ccc;

int gen(ll num, int c) {
    // cout << num << " " << c << endl;
    for (ll i = 2; i < 10; i++) {
        if (num * i >= n) {
            return 1;
        } else {
            if (ccc[num * i] == -1) {
                return 1;
            } else if (ccc[num * i] == 0) {
                int g = gen(num * i, c ^ 0b01);
                ccc[num * i] = g;
                if (g == -1) return 1;
            }
        }
    }
    return -1;
}

int main() {
    cin >> n;
    if (gen(1, 0) == 1) {
        cout << "Stan wins." << endl;
    } else {
        cout << "Ollie wins." << endl;
    }
    // cout << gen(1, 0) << endl;
    return 0;
}