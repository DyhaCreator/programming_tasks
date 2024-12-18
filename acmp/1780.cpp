#include <iostream>
#include <vector>
using namespace std;
using ll = unsigned long long;

const int INF = 1e9 + 7;

struct big{
    vector<ll> a;
    big() {
        a = vector<ll>(1);
    }
    void add(big &b) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] + b.a[i] < a[i]) {
                if (i + 1 >= a.size()) {
                    a.push_back(1);
                    b.a.push_back(0);
                } else
                    a[i + 1]++;
            }
            a[i] += b.a[i];
        }
    }
    void f(big &b) {
        a = b.a;
    }
};

int main() {
    int n;
    cin >> n;
    big a = big();
    big b = big();
    b.a[0] = 1;
    for (int i = 0; i < n; i++) {
        big c = big();
        c.f(a);
        a.add(b);
        b.f(c);
    }
    cout << a.a.size() << endl;
    /*for (auto &x : a.a)
        cout << x << " ";
    cout << endl;
    /*for (auto &x : b.a)
        cout << x << " ";
    cout << endl;*/

    return 0;
}