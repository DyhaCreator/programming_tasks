#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n1, n2, n3, n4;
    cin >> n1;
    vector<int> a(n1);
    for (auto &x : a)
        cin >> x;
    cin >> n2;
    vector<int> b(n2);
    for (auto &x : b)
        cin >> x;
    cin >> n3;
    vector<int> c(n3);
    for (auto &x : c)
        cin >> x;
    cin >> n4;
    vector<int> d(n4);
    for (auto &x : d)
        cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    int ansi = 0;
    int ansj = 0;
    int ansk = 0;
    int ansl = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int ans, th;
    for (int i = 0; i < n1; i++) {
        for (int o = 0; o < 5; o++) {
        while (j < n2 && a[i] > b[j]) {
            ans = max(max(a[ansi], b[ansj]), max(c[ansk], d[ansl])) - min(min(a[ansi], b[ansj]), min(c[ansk], d[ansl]));
            th = max(max(a[i], b[j]), max(c[k], d[l])) - min(min(a[i], b[j]), min(c[k], d[l]));
            /*cout << ansi << " " << ansj << " " << ansk << " " << ansl << " " << ans << endl;
            cout << i << " " << j << " " << k << " " << l << " " << th << endl;
            cout << endl;*/
            if (ans > th) {
                ansi = i;
                ansj = j;
            }
            j++;
        }
        ans = max(max(a[ansi], b[ansj]), max(c[ansk], d[ansl]))
         - min(min(a[ansi], b[ansj]), min(c[ansk], d[ansl]));
        th = max(max(a[i], b[j]), max(c[k], d[l])) - min(min(a[i], b[j]), min(c[k], d[l]));
        /*cout << ansi << " " << ansj << " " << ansk << " " << ansl << " " << ans << endl;
        cout << i << " " << j << " " << k << " " << l << " " << th << endl;
        cout << endl;*/
        if (ans > th) {
            ansi = i;
            ansj = j;
        }


        while (k < n3 && a[i] > c[k]) {
            ans = max(max(a[ansi], b[ansj]), max(c[ansk], d[ansl]))
             - min(min(a[ansi], b[ansj]), min(c[ansk], d[ansl]));
            th = max(max(a[i], b[j]), max(c[k], d[l])) - min(min(a[i], b[j]), min(c[k], d[l]));
            /*cout << ansi << " " << ansj << " " << ansk << " " << ansl << " " << ans << endl;
            cout << i << " " << j << " " << k << " " << l << " " << th << endl;
            cout << endl;*/
            if (ans > th) {
                ansi = i;
                ansk = k;
            }
            k++;
        }
        ans = max(max(a[ansi], b[ansj]), max(c[ansk], d[ansl]))
         - min(min(a[ansi], b[ansj]), min(c[ansk], d[ansl]));
        th = max(max(a[i], b[j]), max(c[k], d[l]))
         - min(min(a[i], b[j]), min(c[k], d[l]));
        /*cout << ansi << " " << ansj << " " << ansk << " " << ansl << " " << ans << endl;
        cout << i << " " << j << " " << k << " " << l << " " << th << endl;
        cout << endl;*/
        if (ans > th) {
            ansi = i;
            ansk = k;
        }


        while (l < n4 && a[i] > d[l]) {
            ans = max(max(a[ansi], b[ansj]), max(c[ansk], d[ansl]))
             - min(min(a[ansi], b[ansj]), min(c[ansk], d[ansl]));
            th = max(max(a[i], b[j]), max(c[k], d[l]))
             - min(min(a[i], b[j]), min(c[k], d[l]));
            if (ans > th) {
                ansi = i;
                ansl = l;
            }
            l++;
        }
        ans = max(max(a[ansi], b[ansj]), max(c[ansk], d[ansl]))
         - min(min(a[ansi], b[ansj]), min(c[ansk], d[ansl]));
        th = max(max(a[i], b[j]), max(c[k], d[l]))
         - min(min(a[i], b[j]), min(c[k], d[l]));
        if (ans > th) {
            ansi = i;
            ansl = l;
        }
        }
    }
    cout << a[ansi] << " " << b[ansj] << " " << c[ansk] << " " << d[ansl] << endl;
    return 0;
}