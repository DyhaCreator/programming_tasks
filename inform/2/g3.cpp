#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<stack<string>> a(n);
    for (int i = 0; i < k; i++) {
        int id, nnn;
        cin >> id >> nnn;
        id--;
        // cout << id << " " << nnn << endl;
        if (nnn == 8) {
            if (a[id].size() > 0 && a[id].top() != "//") a[id].pop();
        } else if (nnn == 13) {
            a[id].push("//");
        } else {
            string str = "";
            str.push_back(char(nnn));
            a[id].push(str);
        }
    }
    for (int i = 0; i < n; i++) {
        string str = "";
        while (!a[i].empty()) {
            str += a[i].top();
            a[i].pop();
        }
        reverse(str.begin(), str.end());
        cout << str << endl;
    }
    return 0;
}