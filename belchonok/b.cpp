#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int> f() {
    vector<int>ans = {2};
    for (int i = 3; i < 100; i++) {
        bool b = false;
        for (int j = 0; j < ans.size(); j++) {
            if (i % ans[j] == 0) {
                b = true;
                break;
            }
        }
        if (b == false) {
            ans.push_back(i);
        }
    }
    return ans;
}

int sum(int a) {
    int ans = 0;
    while (a > 0) {
        ans += a % 10;
        a /= 10;
    }
    return ans;
}

int main() {
    vector<int>a = f();
    for (auto x : a)
        cout << x << " ";
    cout << endl;
    for (int i = 0; i < 12345678; i++) {
        int s = sum(i);
        if (s > 40 && find(a.begin(), a.end(), s) != a.end()) {
            //cout << i << endl;
        }
    }
    return 0;
}