#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int nut;

void rec(int n, vector<int>ans) {
    //cout << n << endl;
    if (n <= 0) {
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
        return;
    }
    ans.push_back(0);
    for (int i = 1; i <= n; i++) {
        ans[ans.size() - 1] = i;
        rec(n - i, ans);
    }
}

int main() {
    cin >> nut;
    vector<int>ans = vector<int>();
    rec(nut, ans);
    return 0;
}