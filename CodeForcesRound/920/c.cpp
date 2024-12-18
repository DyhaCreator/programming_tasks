#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n, f, a, b;
        cin >> n >> f >> a >> b;
        vector<ll>m = vector<ll>(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            cin >> m[j];
        }
        ll ans = a;
        int last = a;
        for (int j = 1; j <= n; j++) {
            if (ans + b - last < ans + (m[j] - m[j - 1]) * a) {
                ans = ans + b - last;
                last = 0;
            } else {
                ans = ans + (m[j] - m[j - 1]) * a;
                last = a;
            }
            //ans = std::min(ans + b, ans + (m[j] - m[j - 1]) * a);
            //cout << ans << " ";
            if (ans >= f) {
                //cout << "No" << endl;
                break;
            }
        }
        if (ans < f) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        //cout << ans << endl;
    }
    return 0;
}