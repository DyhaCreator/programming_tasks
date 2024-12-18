#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        string a = "", b = "";
        reverse(s.begin(), s.end());
        for (int j = 0; j < s.size(); j++) {
            if (j % 2 == 0) a.push_back(s[j]);
            else b.push_back(s[j]);
        }
        s = b + a;
    }
    cout << s << endl;
    return 0;
}