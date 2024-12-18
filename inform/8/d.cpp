#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a, b;
    cin >> a >> b;
    string ans = "";
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size()) {
        string l = "", r = "";
        int len = min(a.size() - i, b.size() - j);
        for (int k = 0; k < len; k++) l.push_back(a[i + k]);
        for (int k = 0; k < len; k++) r.push_back(b[j + k]);
        if (l > r) {
            ans.push_back(a[i]);
            i++;
        } else {
            ans.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size()) ans.push_back(a[i++]);
    while (j < b.size()) ans.push_back(b[j++]);
    cout << ans << endl;
    return 0;
}