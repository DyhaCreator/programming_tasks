#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll>vec(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        bool b = false;
        for (int j = 0; j < i; j++) {
            if (vec[j] == vec[i]) {
                ans -= vec[i];
                b = true;
                break;
            }
        }
        if (!b) {
            ans += vec[i];
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
    
    return 0;
}