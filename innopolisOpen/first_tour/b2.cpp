#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#define ll long long
using namespace std;

int n, x, y;
vector<ll>days;

bool f(ll day) {
    for (int i = 0; i < n; i++) {
        if ((days[i] - day + 1) % (x + y) > x || (days[i] - day + 1) % (x + y) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> x >> y;
    days = vector<ll>(n);
    for (auto &x : days)
        cin >> x;
    vector<ll>a = vector<ll>(n);
    for (int i = 0; i < n; i++) {
        a[i] = (days[i] - 1) % (x + y);
    }
    unordered_set<ll>st;
    for (auto z : a)
        st.insert(z);
    for (auto i : st) {
        if (f(i + 1) == 1) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}