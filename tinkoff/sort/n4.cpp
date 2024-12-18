#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int ans = 0;

struct skier{
    float time, kilo = 0;
    skier() {}
};

bool comp(skier a, skier b) {
    if (a.kilo > b.kilo) ans++;
    return a.kilo > b.kilo;
}

int main() {
    int n, l;
    cin >> n >> l;
    vector<skier>a = vector<skier>(n);
    for (auto &x : a)
        cin >> x.time;
    int it_s = 0;
    for (int i = 0; i < n; i++) {
        a[i].kilo += 1.0/a[i].time * (n - i);
    }
    while (a.begin() + it_s != a.end() - 1) {
        sort(a.begin() + it_s, a.end(), comp);
        /*for (auto x : a)
            cout << x.time << " ";
        cout << endl;
        for (auto x : a)
            cout << x.kilo << " ";
        cout << endl;
        cout << ans << endl;*/
        if (a[it_s].kilo > l) {
            it_s++;
        }
        for (int i = 0; i < n; i++) {
            a[i].kilo += 1.0/a[i].time;
        }
    }
    cout << ans << endl;
    return 0;
}