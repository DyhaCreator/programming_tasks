#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long 
using namespace std;

vector<int>answer = vector<int>();

void rec(int n, vector<int>ans) {
    if (n == 0) {
        answer = ans;
        if (answer.size() < 4) {
            for (int i = answer.size(); i < 4; i++) {
                answer.push_back(0);
            }
        }
        for (auto x : answer)
            cout << x << " ";
        cout << endl;
        exit(0);
        return;
    }
    if (ans.size() >= 4) {
        return;
    }
    int a = 1;
    ans.push_back(1);
    while (a * a <= n) {
        ans[ans.size() - 1] = a;
        rec(n - a * a, ans);
        a++;
    }
}

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    rec(n, vector<int>());
    return 0;
}