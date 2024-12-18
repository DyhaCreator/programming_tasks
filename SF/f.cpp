#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>p = vector<int>(n);
    for (auto &x : p)
        cin >> x;
    float c = 0;
    vector<int>a = vector<int>();
    vector<int>b = vector<int>();
    for (int i = 0; i < n; i++) {
        c += p[i];
    }
    c /= n;
    for (int i = 0; i < n; i++) {
        if (p[i] > c) {
            a.push_back(p[i]);
        } else {
            b.push_back(p[i]);
        }
    }
    map<int, int>m;
    for (auto x : a)
        m[x]++;
    for (auto x : b)
        m[x]++;
    ll maxIndex = 0;
    for (int i = 0; i < b.size(); i++) {
        if (m[b[maxIndex]] < m[b[i]]) {
            maxIndex = i;
        } else if (m[b[maxIndex]] == m[b[i]] && b[maxIndex] < b[i]) {
            maxIndex = i;
        }
    }
    cout << b[maxIndex] << " ";
    maxIndex = 0;
    for (int i = 0; i < a.size(); i++) {
        if (m[a[maxIndex]] < m[a[i]]) {
            maxIndex = i;
        } else if (m[a[maxIndex]] == m[a[i]] && a[maxIndex] < a[i]) {
            maxIndex = i;
        }
    }
    cout << a[maxIndex] << "\n";
    return 0;
}

/*

7
16
19
18
45
20
55
16

*/