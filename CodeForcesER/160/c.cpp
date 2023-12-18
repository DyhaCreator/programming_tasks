#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll cp(ll n) {
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ans = ans << 1;
    }
    return ans;
}

struct mult{
    vector<ll>sum = vector<ll>(1, 0);
    mult() {}
    void add(ll x) {
        sum.push_back(cp(x) + sum.back());
    }
    bool get(ll w) {
        for (int i = 1; i < sum.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (sum[i] - sum[j] == w) return true;
            }
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n;
    mult m = mult();
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            m.add(b);
        } else if (a == 2) {
            cout << ((m.get(b))?"YES":"NO") << endl;
        }
    }
    return 0;
}

/*

7
1 0
1 1
1 2
1 10
2 4
2 6
2 7


*/