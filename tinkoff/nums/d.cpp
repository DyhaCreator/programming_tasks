#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#define ll long long
using namespace std;

vector<int>prime = vector<int>();
set<int>st;
map<int, int>mp;
vector<int>vst = vector<int>();
vector<int>vans = vector<int>();

bool isPrime(int n) {
    for (auto x : prime) {
        if (n % x == 0) {
            return false;
        }
    }
    return true;
}

int pow(int a, int b) {
    int ans = 1;
    for (int i = 0; i < b; i++) {
        ans *= a;
    }
    return ans;
}

void rec(vector<int>a) {
    if (a.size() == st.size()) {
        int ans = 1;
        for (int i = 0; i < a.size(); i++) {
            ans *= pow(vst[i], a[i]);
        }
        vans.push_back(ans);
        return;
    }
    a.push_back(0);
    for (int i = 0; i <= mp[vst[a.size() - 1]]; i++) {
        a[a.size() - 1] = i;
        rec(a);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }
    int i = 0;
    while (n > 1) {
        while (i < int(prime.size()) && n % prime[i] != 0) {
            i++;
        }
        if (i == int(prime.size())) {
            st.insert(n);
            mp[n]++;
            break;
        }
        st.insert(prime[i]);
        mp[prime[i]]++;
        n /= prime[i];
    }
    int ans = 1;
    for (auto x : st) {
        ans *= (mp[x] + 1);
    }
    cout << ans << endl;
    for (auto x : st)
        vst.push_back(x);
    rec(vector<int>());
    sort(vans.begin(), vans.end());
    for (auto x : vans)
        cout << x << " ";
    cout << endl;
    return 0;
}