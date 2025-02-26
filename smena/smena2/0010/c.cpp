#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string a = "";
    for (int i = 0; i < n; i++)
        a.push_back('a');
    cout << a << endl;
    int sum;
    cin >> sum;
    vector<int> ans = {};
    for (int i = 0; i < n; i++) {
        string b = "";
        for (int j = 0; j < n; j++)
            b.push_back('a');
        b[i] = 'z';
        cout << b << endl;
        int sum2;
        cin >> sum2;
        ans.push_back(-(((sum2 - sum) - 25) / 2));
    }
    for (auto &x : ans)
        cout << char(x + 'a');
    cout << endl;
    return 0;
}