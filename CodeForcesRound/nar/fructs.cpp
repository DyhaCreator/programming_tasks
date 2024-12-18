#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#define ll long long
using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll>a(n);
    for (auto &x : a)
        cin >> x;
    map<string, ll>mp;
    set<string>st;
    for (int i = 0; i < m; i++) {
        string name;
        cin >> name;
        st.insert(name);
        mp[name]++;
    }
    vector<ll>b = {};
    for (auto &x : st) {
        b.push_back(mp[x]);
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    ll ans = 0;
    for (int i = 0; i < b.size(); i++) {
        ans += b[i] * a[i];
    }
    cout << ans << " ";
    reverse(a.begin(), a.end());
    //reverse(b.begin(), b.end());
    /*for (auto &x : a)
        cout << x << " ";
    cout << endl;
    for ( auto &x : b)
        cout << x << " ";
    cout << endl;*/
    ans = 0;
    for (int i = 0; i < b.size(); i++) {
        ans += b[i] * a[i];
    }
    cout << ans << endl;
    return 0;
}