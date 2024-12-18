#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> a;
    ll i1 = 0;
    ll i2 = 0;
    int size = 0;
    while (size < n) {
        if (i1 * i1 < i2 * i2 * i2) {
            //a.push_back(i1 * i1);
            i1++;
        } else if (i1 * i1 > i2 * i2 * i2) {
            //a.push_back(i2 * i2 * i2);
            i2++;
        } else {
            //a.push_back(i1 * i1);
            i1++;
            i2++;
        }
        size++;
    }
    cout << min(i1 * i1, i2 * i2 * i2) << endl;
    return 0;
}