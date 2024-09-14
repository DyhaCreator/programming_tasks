#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];
    /*for (auto &x : pref)
        cout << x << " ";
    cout << endl;*/
    int bestI = 1;
    int bestJ = 0;
    int j = 0;
    for (int i = 1; i <= n; i++) {
        if (pref[i] - pref[j] > pref[bestI] - pref[bestJ]) {
            bestI = i;
            bestJ = j;
        }
        if (pref[i] < pref[j])
            j = i;
    }
    cout << bestJ + 1 << " " << bestI << " " << pref[bestI] - pref[bestJ] << endl;
    return 0;
}