#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int nut;

void rec(int n, vector<int>ans) {
    if (n <= 0) {
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
        return;
    }
    ans.push_back(0);
    for (int i = 1; n - i >= 0 && i <= ans[ans.size() - 2]; i++) {
        ans[ans.size() - 1] = i;
        rec(n - i, ans);
    }
}

int main() {
    cin >> nut;
    vector<int>ans = vector<int>();
    ans.push_back(0);
    for (int i = 1; i <= nut; i++) {
        ans[ans.size() - 1] = i;
        rec(nut - i, ans);
    }
    return 0;
}