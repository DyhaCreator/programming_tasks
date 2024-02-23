#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
#define prvec(vec) for(auto &x:vec)cout<<x<<" ";cout<<endl;
#define all(vec) vec.begin(),vec.end()
using namespace std;

void solveA() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (auto &x : vec)
            cin >> x;
        int findex = 0;
        int eindex = -1;
        while (vec[findex] == 0) {
            findex++;
        }
        for (int j = 0; j < n; j++) {
            if (vec[j] == 1) {
                eindex = j;
            }
        }
        int ans = 0;
        for (int j = findex; j < eindex; j++) {
            if (vec[j] == 0) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}

struct mon{
    ll a, x;
    mon() {}
    mon(ll a, ll x) {
        this->a = a;
        this->x = x;
    }
};

bool comp(mon &a, mon &b) {
    return abs(a.x) < abs(b.x);
}

void solveB() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n, k;
        cin >> n >> k;
        vector<mon> m(n);

        for (auto &[a, x] : m)
            cin >> a;
        for (auto &[a, x] : m)
            cin >> x;

        sort(m.begin(), m.end(), comp);

        for (ll j = 1; j < n; j++) {
            m[j].a += m[j - 1].a;
        }

        /*for (auto &x : m)
            cout << x.a << " ";
        cout << endl;*/
        bool f = false;
        for (int j = 0; j < n; j++) {
            //cout << (m[j].a + k - 1) / k << endl;
            if ((m[j].a + k - 1) / k > abs(m[j].x)) {
                cout << "NO" << endl;
                f = true;
                break;
            }
        }
        if (!f) cout << "YES" << endl;
    }
}

int main() {
    solveB();
    return 0;
}