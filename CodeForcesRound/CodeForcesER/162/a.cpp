#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
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


void solveD2() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int n;
        cin >> n;
        vector<int> mp(n);
        for (auto &x : mp)
            cin >> x;
        vector<int> left(n, -1);
        for (int i = 1; i < n; i++) {
            if (mp[i] == mp[i - 1]) {
                left[i] = left[i - 1];
            } else {
                left[i] = i - 1;
            }
        }

        /*for (auto &x : left)
            cout << x << " ";
        cout << endl;*/

        vector<ll> prefSum(n + 1);
        for (int i = 1; i <= n; i++) {
            prefSum[i] = prefSum[i - 1] + mp[i - 1];
        }
        prefSum.push_back(prefSum.back());

        vector<int> ansLeft(n);

        for (int i = 0; i < n; i++) {
            int l = 0;
            int r = i;
            // cout << l << " " << r << endl;
            while (l < r) {
                int mid = (l + r) / 2;
                bool can = false;
                if (mid == 1) {
                    can = true;
                } else if (i > 1 && left[i - 1] >= i - mid) {
                    can = true;
                }

                // cout << left[i - 1] << " " << i - mid << endl;

                ll sum = prefSum[i] - prefSum[i - mid];

                // cout << mid << " " << can << " " << sum << endl;
                if (sum <= mp[i] || can == false) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
                // cout << l << " " << r << endl;
                // cout << endl;
            }
            int mid = l;
            bool can = false;
            if (mid == 1) {
                can = true;
            } else if (i > 1 && left[i - 1] >= i - mid) {
                can = true;
            }
            ll sum = prefSum[i] - prefSum[i - mid];
            if (sum <= mp[i] || can == false) {
                ansLeft[i] = INF;
            } else {
                ansLeft[i] = l;
            }
        }

        /*for (auto &x : ansLeft)
            cout << x << " ";
        cout << endl;*/

        vector<int> ansRight(n);

        for (int i = n - 1; i >= 0; i--) {
            // cout << i << endl;
            int l = 0;
            int r = n - i - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                bool can = false;
                if (mid == 1) {
                    can = true;
                } else if (i < n - 1 && left[i + mid] > i) {
                    can = true;
                }
                ll sum = 0;
                if (i + 1 + mid < n + 2) {
                    sum = prefSum[i + 1 + mid] - prefSum[i + 1];
                }

                // cout << mid << " " << sum << " " << can << endl;

                if (sum <= mp[i] || can == false) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
                // cout << l << " " << r << endl;
                // cout << endl;
            }
            // cout << l << endl;
            // cout << endl;
            int mid = l;
            bool can = false;
            if (mid == 1) {
                can = true;
            } else if (i < n - 1 && left[i + mid] > i) {
                can = true;
            }
            ll sum = 0;
            if (i + 1 + mid < n + 2) {
                sum = prefSum[i + 1 + mid] - prefSum[i + 1];
            }
            if (sum <= mp[i] || can == false) {
                ansRight[i] = INF;
            } else {
                ansRight[i] = l;
            }
        }
        /*for (auto &x : ansRight)
            cout << x << " ";
        cout << endl;*/

        for (int i = 0; i < n; i++) {
            if (min(ansLeft[i], ansRight[i]) == INF) {
                cout << -1 << " ";
            } else {
                cout << min(ansLeft[i], ansRight[i]) << " ";
            }
        }
        cout << endl;
    }
}

void solveD3() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int n;
        cin >> n;
        vector<int> mp(n);
        for (auto &x : mp)
            cin >> x;
        vector<int> left(n);
        left[0] = -1;
        for (int i = 1; i < n; i++) {
            if (mp[i] == mp[i - 1]) {
                left[i] = left[i - 1];
            } else {
                left[i] = i - 1;
            }
        }

        vector<int> right(n);
        right[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (mp[i] == mp[i + 1]) {
                right[i] = right[i + 1];
            } else {
                right[i] = i + 1;
            }
        }

        vector<ll> prefSum(n + 1);
        for (int i = 1; i <= n; i++)
            prefSum[i] = prefSum[i - 1] + mp[i - 1];

        for (auto &x : left)
            cout << x << " ";
        cout << endl;
        for (auto &x : right)
            cout << x << " ";
        cout << endl;
        
        vector<int> leftAns(n);
        for (int i = 0; i < n; i++) {
            int len = 0;
            int l = 0;
            int r = i;
            while (l < r) {
                int mid = (l + r) / 2;
                int sum = prefSum[i] - prefSum[i - mid];
                if (sum <= mp[i]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            cout << l << " ";
            leftAns[i]
        }
        cout << endl;

        vector<int> rightAns(n);
        for (int i = 0; i < n; i++) {
            int len = 0;
            int l = 0;
            int r = n - i - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                int sum = prefSum[i + mid + 1] - prefSum[i + 1];
                if (sum <= mp[i]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            cout << l << " ";
        }
        cout << endl;
        cout << endl;
    }
}

int main() {
    solveD3();
    return 0;
}