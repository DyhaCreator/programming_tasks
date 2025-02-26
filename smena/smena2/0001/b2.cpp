#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a = {};
    for (auto &x : s)
        a.push_back(x - '0');
    int ost = 0;
    for (auto &x : a) {
        ost *= 10;
        ost += x;
        ost = ost % 3;
    }
    if (ost == 0) {
        cout << s << endl;
        return 0;
    } else if (ost == 1) {
        int mn = -1;
        for (int i = 0; i < n; i++)
            if (a[i] % 3 == 1 && (mn == -1 || a[mn] > a[i])) mn = i;
        if (mn != -1) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (i != mn && (cnt > 0 || a[i] != 0)) {
                    cnt++;
                    cout << a[i];
                }
            }
            if (cnt == 0) cout << 0;
            cout << endl;
        } else {
            int cnt = 0;
            mn = -1;
            for (int i = 0; i < n; i++)
                if (a[i] % 3 == 2 && (mn == -1 || a[mn] > a[i])) mn = i;
            int mn2 = -1;
            for (int i = 0; i < n; i++)
                if (i != mn && a[i] % 3 == 2 && (mn2 == -1 || a[mn2] > a[i])) mn2 = i;
            for (int i = 0; i < n; i++)
                if (i != mn && i != mn2 && (cnt > 0 || a[i] != 0)) {
                    cout << a[i];
                    cnt++;
                }
            if (cnt == 0) cout << 0;
            cout << endl;
        }
    } else {
        int mn = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] % 3 == 2 && (mn == -1 || a[mn] > a[i])) mn = i;
        }
        if (mn != -1) {
            int cnt = 0;
            for (int i = 0; i < n; i++)
                if (i != mn && (cnt > 0 || a[i] != 0)) {
                    cnt++;
                    cout << a[i];
                }
            if (cnt == 0) cout << 0;
            cout << endl;
        } else {
            int cnt = 0;
            mn = -1;
            for (int i = 0; i < n; i++)
                if (a[i] % 3 == 1 && (mn == -1 || a[mn] > a[i])) mn = i;
            int mn2 = -1;
            for (int i = 0; i < n; i++)
                if (i != mn && a[i] % 3 == 1 && (mn2 == -1 || a[mn2] > a[i])) mn2 = i;
            for (int i = 0; i < n; i++)
                if (i != mn && i != mn2 && (cnt > 0 || a[i] != 0)) {
                    cout << a[i];
                    cnt++;
                }
            if (cnt == 0) cout << 0;
            cout << endl;
        }
    }
    return 0;
}