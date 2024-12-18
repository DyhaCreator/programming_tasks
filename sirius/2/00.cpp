#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

bool comp(string &a, string &b) {
    return a + b > b + a;
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end(), comp);
    string ans = "";
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}