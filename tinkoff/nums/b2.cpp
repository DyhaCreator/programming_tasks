#include <iostream>
#include <vector>
#include <set>
#include <map>
#define ll long long
using namespace std;

vector<int>prime = vector<int>();

bool isPrime(int n) {
    for (int i = 0; i < prime.size(); i++) {
        if (n % prime[i] == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }
    set<int>st;
    map<int, int>mp;
    int i = 0;
    while (n > 1) {
        while (i < prime.size() && n % prime[i] != 0) {
            i++;
        }
        if (i == prime.size()) {
            st.insert(n);
            mp[n]++;
            break;
        }
        n /= prime[i];
        st.insert(prime[i]);
        mp[prime[i]]++;
    }
    vector<int>ans = vector<int>();
    for (auto x : st)
        ans.push_back(x);
    for (int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i] << ((mp[ans[i]] == 1)?"":"^" + to_string(mp[ans[i]])) << "*";
    }
    cout << ans[ans.size() - 1] << ((mp[ans[ans.size() - 1]] == 1)?"":"^" + to_string(mp[ans[ans.size() - 1]]));
    return 0;
}