#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int cp(int n) {
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = ans << 1;
    }
    return ans;
}

struct mult{
    ll sum = 0;
    mult() {}
    void add(ll x) {
        sum += cp(x);
    }
    bool get(ll w) {
        return (sum >= w);
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