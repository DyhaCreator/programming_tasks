#include <iostream>
#include <queue>
#define ll long long
using namespace std;

int main() {
    vector<ll>q = vector<ll>();
    ll n;
    cin >> n;
    ll min = 1e18 + 1;
    ll min_index = -1;
    ll size = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            ll x;
            cin >> x;
            q.push_back(x);
            if (x < min) {
                min = x;
                min_index = size;
            }
            size++;
        } else if (a == 2) {
            cout << q[0] << endl;
            q.erase(q.begin());
            size--;
            min_index--;
            if (min_index == -1) {
                min = 1e18;
                for (int i = 0; i < size; i++) {
                    if (q[i] < min) {
                        min = q[i];
                        min_index = i;
                    }
                }
            }
        } else if (a == 3) {
            ll x;
            cin >> x;
            cout << q[x - 1] << endl;
        } else if (a == 4) {
            cout << min << endl;
        }
    }
    return 0;
}