#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int sum(int n) {
    int ans = 0;
    while (n > 0) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
    int l, r;
    cin >> l >> r;
    vector<int>ans = vector<int>();

    int lsum = sum(l);
    for (int i = 1; i < 10; i++) {
        if (i % 2 == l % 2) {
            int num = i * 100 + lsum;
            if (sum(num) == r % 100 && num % 2 == (r / 100) % 2) {
                ans.push_back(l);
            }
        }
    }

    int rsum = sum(r);
    for (int i = 1; i < 10; i++) {
        if (i % 2 == r % 2) {
            int num = i * 100 + rsum;
            if (sum(num) == l % 100 && num % 2 == (l / 100) % 2) {
                ans.push_back(r);
            }
        }
    }

    for (int num = 100; num < 999; num++) {
        if ((num % 2 == (l / 100) % 2) && (sum(num) == l % 100) &&
            (num % 2 == (r / 100) % 2) && (sum(num) == r % 100)) {
            ans.push_back(num);
        }
    }
    if (ans.size() == 0) {
        cout << -1 << endl;
        return 0;
    }
    int min = 10000;
    for (auto x : ans)
        min = std::min(x, min);
    cout << min << endl;

    return 0;
}