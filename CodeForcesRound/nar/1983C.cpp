#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    for (auto &x : c)
        cin >> x;
    ll tot = 0;
    for (auto &x : a)
        tot += x;
    vector<int> indexA(n, -1);
    int j = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        while (sum >= (tot + 2) / 3) {
            sum -= a[j];
            j++;
        }
        indexA[i] = j - 1;
    }
    vector<int> indexB(n, -1);
    j = 0;
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += b[i];
        while (sum >= (tot + 2) / 3) {
            sum -= b[j];
            j++;
        }
        indexB[i] = j - 1;
    }
    vector<int> indexC(n, -1);
    j = 0;
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += c[i];
        while (sum >= (tot + 2) / 3) {
            sum -= c[j];
            j++;
        }
        indexC[i] = j - 1;
    }
    /*for (auto &x : indexA)
        cout << x << " ";
    cout << endl;
    for (auto &x : indexB)
        cout << x << " ";
    cout << endl;
    for (auto &x : indexC)
        cout << x << " ";
    cout << endl;*/
    for (int i = 0; i < n; i++) {
        if (indexA[i] > -1) {
            for (int j = 0; j < n; j++) {
                if ((j < indexA[i] && indexB[j] > -1) || indexB[j] > i) {
                    for (int k = 0; k < n; k++) {
                        if ((k < indexA[i] || indexC[k] > i) && (k < indexB[j] || indexC[k] > j) && indexC[k] > -1) {
                            cout << indexA[i] + 1 << " " << i + 1 << " "
                                 << indexB[j] + 1 << " " << j + 1 << " "
                                 << indexC[k] + 1 << " " << k + 1 << endl;
                            // cout << i << " " << j << " " << k << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}