#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a;
    cin >> a;
    int n = a.size();
    string c = "0";
    for (int i = 0; i < n; i++) {
        string b = "";
        for (int j = 0; j < n; j++) {
            if (j != i) b.push_back(a[j]);
        }
        if (c == "0" || b < c) c = b;
    }
    cout << c << endl;
    return 0;
}