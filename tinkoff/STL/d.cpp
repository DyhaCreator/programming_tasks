#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    vector<int>b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    set<int>ans;
    for (int i = 0; i < n; i++) {
        if (find(b.begin(), b.end(), a[i]) == b.end()) {
            ans.insert(a[i]);
        }
    }
    for (int i = 0; i < m; i++) {
        if (find(a.begin(), a.end(), b[i]) == a.end()) {
            ans.insert(b[i]);
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans) 
        cout << x << " ";
    cout << endl;
    return 0;
}