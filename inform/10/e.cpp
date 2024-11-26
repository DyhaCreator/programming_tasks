#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, t;
    cin >> n >> t;
    map<string, string> mp;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (t == 0) {
            mp[a] = b;
        } else {
            mp[b] = a;
        }
    }
    string s;
    while (cin >> s) {
        if (mp[s] != "") {
            cout << mp[s] << " ";
        } else {
            cout << "?" << " ";
        }
    }
    cout << endl;
    return 0;
}