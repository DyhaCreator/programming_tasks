#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int nut;

void rec(int n, vector<int>ans) {
    if (n <= 0) {
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
        return;
    }
    ans.push_back(0);
    for (int i = n; i >= ans[ans.size() - 2]; i--) {
        ans[ans.size() - 1] = i;
        rec(n - i, ans);
    }
}

int main() {
    cin >> nut;
    vector<int>ans = vector<int>();
    ans.push_back(0);
    for (int i = nut; i >= 1; i = i >> 1) {
        ans[ans.size() - 1] = i;
        rec(nut - i, ans);
    }
    return 0;
}