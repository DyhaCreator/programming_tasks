#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n1;
    cin >> n1;
    vector<int> a(n1);
    for (auto &x : a)
        cin >> x;
    int n2;
    cin >> n2;
    vector<int> b(n2);
    for (auto &x : b)
        cin >> x;
    int n3;
    cin >> n3;
    vector<int> c(n3);
    for (auto &x : c)
        cin >> x;
    int n4;
    cin >> n4;
    vector<int> d(n4);
    for (auto &x : d)
        cin >> x;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    int mn = min(min(a[0], b[0]), min(c[0], d[0]));
    int mx = max(max(a[0], b[0]), max(c[0], d[0]));
    int diff = abs(mn - mx);
    int ansi = 0;
    int ansj = 0;
    int ansk = 0;
    int ansl = 0;
    int i = 0, j = 0, k = 0, l = 0;
    while (i < n1 && j < n2 && k < n3 && l < n4) {
        mn = min(min(a[i], b[j]), min(c[k], d[l]));
        mx = max(max(a[i], b[j]), max(c[k], d[l]));
        int diffR = abs(mn - mx);
        if (diffR < diff) {
            diff = diffR;
            ansi = i;
            ansj = j;
            ansk = k;
            ansl = l;
        }
        while (i < n1 && mn == a[i])
            i++;
        while (j < n2 && mn == b[j])
            j++;
        while (k < n3 && mn == c[k])
            k++;
        while (l < n4 && mn == d[l])
            l++;
    }
    cout << a[ansi] << " " << b[ansj] << " " << c[ansk] << " " << d[ansl] << endl;
    return 0;
}