#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#define ll long long
#define INF 1000000000000007
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

void solveC() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        vector<ll> prefSum(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            prefSum[j] = prefSum[j - 1] + a[j - 1] - 1;
        }

        vector<ll> count(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            if (a[j - 1] == 1) {
                count[j] = count[j - 1] + 1;
            } else {
                count[j] = count[j - 1];
            }
        }

        for (int j = 0; j < q; j++) {
            int l, r;
            cin >> l >> r;
            l--;
            if (r - l == 1) {
                cout << "NO" << endl;
                continue;
            }

            ll sum = prefSum[r] - prefSum[l];
            ll cou = count[r] - count[l];
            if (sum >= cou) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            // cout << sum << " " << cou << endl;
        }
    }
}

void solveD() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto &x : a)
            cin >> x;
        

        vector<ll> left(n);
        stack<pair<ll, ll>> stl;
        stl.push({INF, -INF});

        for (int j = 0; j < n; j++) {
            while (stl.top().first <= a[j]) {
                stl.pop();
            }

            left[j] = j - stl.top().second;

            pair<ll, ll> w = stl.top();
            w.first += a[j];
            stl.pop();
            stl.push(w);
            stl.push({a[j], j});
        }

        for (auto &x : left)
            cout << x << " ";
        cout << endl;

        vector<ll> right(n);
        stack<pair<ll, ll>> str;
        str.push({INF, -INF});

        for (int j = n - 1; j >= 0; j--) {
            while (str.top().first <= a[j]) {
                str.pop();
            }

            right[j] = abs(str.top().second - (n - j - 1));

            pair<ll, ll> w = str.top();
            w.first += a[j];
            str.pop();
            str.push(w);
            str.push({a[j], n - j - 1});
        }

        for (auto &x : right)
            cout << x << " ";
        cout << endl;

        for (int j = 0; j < n; j++) {
            ll a = std::min(left[j], right[j]);
            // cout << a << " ";
            if (a >= INF) {
                cout << -1 << " ";
            } else{
                cout << a << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    solveC();
    return 0;
}