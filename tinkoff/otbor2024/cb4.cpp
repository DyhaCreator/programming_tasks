#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
ll n;
bool found = 0;

int f(vector<ll> &num, ll c, ll index) {
    if (found == 1) return 0;
    /*for (auto &x : num)
        cout << x << " ";
    cout << endl;*/
    if (c == n) {
        cout << num.size() << endl;
        for (auto &x : num)
            cout << x << " ";
        cout << endl;
        found = 1;
        return 0;
    }

    if (c < n) {
        int buff = n - c;
        int st = 0;
        while ((1 << st) < buff) {
            st++;
        }
        // cout << (1 << st) << endl;
        if (index - st > 1) {
            num[st] = 1;
            f(num, c + (1 << (st)), st);
            // cout << 111 << endl;
            num[st] = 0;
        }
        if (index - st > 0 && st > 0) {
            num[st - 1] = 1;
            f(num, c + (1 << (st - 1)), st - 1);
            // cout << 222 << endl;
            num[st - 1] = 0;
        }
    } else if (c > n) {
        int buff = c - n;
        int st = 0;
        while ((1 << st) < buff) {
            st++;
        }
        // cout << (1 << st) << endl;
        if (index - st > 1) {
            num[st] = -1;
            f(num, c - (1 << (st)), st);
            // cout << "111" << endl;
            num[st] = 0;
        }
        if (index - st > 0 && st > 0) {
            num[st - 1] = -1;
            f(num, c - (1 << (st - 1)), st - 1);
            // cout << "222" << endl;
            num[st - 1] = 0;
        }
    }

    /*for (int i = 0; i < index - 1; i++) {
        if (c < n) {
            num[i] = 1;
            f(num, c + (1 << i), i);
        } else if (c > n) {
            num[i] = -1;
            // f(num, c - (1 << i), i);
        }
        num[i] = 0;
    }*/
    return 0;
}

int solve() {
    cin >> n;
    found = 0;

    ll st = 0;
    while ((1 << st) < n) {
        st++;
    }

    vector<ll> num(st, 0);
    // cout << n << " " << (1 << st) << endl;
    if (st > 0) {
        num[st - 1] = 1;
        /*for (auto &x : num)
            cout << x << " ";
        cout << endl;*/
        f(num, 1 << (st - 1), st - 1);
        num[st - 1] = 0;
    }
    num.push_back(1);
    /*for (auto &x : num)
        cout << x << " ";
    cout << endl;*/
    f(num, 1 << st, st);

    /*for (ll index = 0; index <= 32; index++) {
        num.push_back(1);
        f(num, 1 << index, index);
        num[num.size() - 1] = 0;
    }*/
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*int nm = 32;
    int a = 1, b = 1;
    nm -= 2;
    while (nm > 0) {
        a += b;
        b = a - b;
        nm--;
    }
    cout << a << endl;*/


    int t;
    cin >> t;
    // unsigned int start_time =  clock();
    while (t--) {
        solve();
    }
    // unsigned int end_time = clock();
    // cout << (double)(end_time - start_time) / CLOCKS_PER_SEC * 10 << endl;
    return 0;
}