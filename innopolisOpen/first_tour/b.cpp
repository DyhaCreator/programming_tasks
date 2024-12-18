#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#define ll long long
using namespace std;

ll n, x, y;
vector<ll>days;

bool f(ll day) {
    for (int i = 0; i < n; i++) {
        //cout << days[i] << " " << fase(days[i], day) << endl;
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
    for (int i = 1; i <= x + y; i++) {
        //bool ans = f(i);
        //cout << i << " " << ans << endl << endl;
        if (f(i) == 1) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}

/*

3 3 1
5 8 11

*/