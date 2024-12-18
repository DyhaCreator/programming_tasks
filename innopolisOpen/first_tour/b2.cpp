#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#define ll long long
using namespace std;

int n, x, y;
vector<ll>a;

bool f(ll day) {
    for (int i = 0; i < n; i++) {
        if (a[i] - day >= x) {
            return false;
        } else if(a[i] - day < 0 && a[i] + x + y - day >= x) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> x >> y;
    a = vector<ll>(n);
    for (int i = 0; i < n; i++) {
        int z;
        cin >> z;
        a[i] = (z - 1) % (x + y);
    }
    unordered_set<ll>st;
    for (auto z : a)
        st.insert(z);
    for (auto i : st) {
        if (f(i) == 1) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}