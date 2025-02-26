#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a;
    cin >> a;
    vector<int> ans = {};
    for (int i = 0; i < 5; i++) {
        string ss;
        cin >> ss;
        if (ss == "bb" || ss[0] == a[0] || ss[1] == a[1])
            ans.push_back(i);
    }
    if (ans.size() == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (auto &x : ans)
        cout << x + 1 << " ";
    cout << endl;
    return 0;
}