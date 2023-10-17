#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#define ll unsigned long long

using namespace std;

int main() {
    set<ll>lng;
    int n;
    cin >> n;
    int j = 0;
    for (int i = 0; lng.size() < n + 1; i++) {
        ll a = i * i * i;
        lng.insert(a);
        while (j * j < a) {
            ll b = j * j;
            lng.insert(b);
            j++;
        }
    }
    for (auto i : lng) {
        cout << i << " ";
    }
    cout << endl;
    int last = 0;
    for (auto i : lng) {
        cout << i - last << " ";
        last = i;
    }
    cout << endl;
    set<ll>::iterator it = lng.begin();
    advance(it, n);
    ll x = *it;
    cout << x << endl;
    return 0;
}