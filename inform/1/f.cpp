#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    ll j = 0;
    ll sum = 0;
    ll len = 0;
    while (sum < n) {
        j++;
        sum += j;
        len++;
    }
    // cout << sum << " " << len << endl;
    ll i = 0;
    while (sum != n) {
        if (sum > n) {
            i++;
            sum -= i;
            len--;
        } else {
            j++;
            sum += j;
            len++;
        }
    }
    cout << len << endl;
    // cout << sum << " " << len << " " << i << " " << j << endl;
    return 0;
}