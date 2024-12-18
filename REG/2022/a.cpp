#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (auto &x : a)
        cin >> x;
    int q;
    cin >> q;
    ll offset = 0;
    ll sum = 0;
    for (auto &x : a)
        sum += x;
    for (int i = 0; i < q; i++) {
        ll w;
        cin >> w;
        if (w == 1) {
            ll index, x;
            cin >> index >> x;
            //sum -= a[(index - 1 + offset) % n];
            //a[(index - 1 + offset) % n] = x;
            index--;
            if (index - offset < 0) {
                sum -= a[n + index - offset];
                a[n + index - offset] = x;
            } else {
                sum -= a[index - offset];
                a[index - offset] = x;
            }
            sum += x;
            cout << sum << endl;
            /*for (int j = 0; j < n; j++) {
                if (j - offset < 0) {
                    cout << a[n + j - offset] << " ";
                } else {
                    cout << a[j - offset] << " ";
                }
            } cout << endl;*/
        } else {
            ll k;
            cin >> k;
            offset += k;
            offset = offset % n;
            cout << sum << endl;
            /*for (int j = 0; j < n; j++) {
                if (j - offset < 0) {
                    cout << a[n + j - offset] << " ";
                } else {
                    cout << a[j - offset] << " ";
                }
            } cout << endl;*/
        }
    }
    return 0;
}