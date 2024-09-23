#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string str;
    cin >> str;
    int n = str.size();
    for (int i = n / 2 + 1; i < n; i++) {
        string s1 = str.substr(0, i);
        string s2 = str.substr(n - i);
        // cout << s1 << " " << s2 << endl;
        if (s1 == s2) {
            cout << "YES" << endl;
            cout << s1 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}