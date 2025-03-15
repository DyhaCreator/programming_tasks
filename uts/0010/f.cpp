#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> a = {};
    vector<int> b = {};
    int f = 0;
    for (auto &x : s1) {
        if (x == '1') f = 1;
        if (f) a.push_back(x - '0');
    }
    f = 0;
    for (auto &x : s2) {
        if (x == '1') f = 1;
        if (f) b.push_back(x - '0');
    }
    reverse(a.begin(), a.end());
    while (a.size() < b.size()) a.push_back(0);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while (b.size() < a.size()) b.push_back(0);
    reverse(b.begin(), b.end());
    /*for (auto &x : a)
        cout << x << " ";
    cout << endl;
    for (auto &x : b)
        cout << x << " ";
    cout << endl;*/
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] == 1 && b[i] == 1) {
            a[i] = 0;
            b[i] = 0;
        } else if (a[i] == 1) {
            if (i + 2 >= n) {
                cout << ">" << endl;
                return 0;
            }
            int j = i + 1;
            while (j + 1 < n && b[j] == 1 && b[j + 1] == 0)
                j += 2;
            if (j + 1 == n || b[j] + b[j] != 2) {
                cout << ">" << endl;
                return 0;
            }
            for (int k = i + 1; k <= j; k+=2)
                b[k] = 0;
            b[j] = 0;
            b[j + 1] = 0;
            a[i] = 0;
        } else if (b[i] == 1) {
            if (i + 2 >= n) {
                cout << "<" << endl;
                return 0;
            }
            int j = i + 1;
            while (j + 1 < n && a[j] == 1 && a[j + 1] == 0)
                j += 2;
            if (j + 1 == n || a[j] + a[j] != 2) {
                cout << "<" << endl;
                return 0;
            }
            for (int k = i + 1; k <= j; k+=2)
                a[k] = 0;
            a[j] = 0;
            a[j + 1] = 0;
            b[i] = 0;
        }
        /*for (auto &x : a)
            cout << x << " ";
        cout << endl;
        for (auto &x : b)
            cout << x << " ";
        cout << endl;*/
    }
    cout << "=" << endl;
    return 0;
}