#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int ans = 0;
int n;
set<int> st;
vector<int> prime = {};

bool isPrime(int n) {
    if (n == 1) return 0;
    for (auto &x : prime)
        if (n != x && n % x == 0)
            return 0;
    return 1;
}

void rec(string &a, vector<int> &used, string b) {
    if (b.size() > 0 && isPrime(stoi(b)) && b[0] != '0') {
        // cout << b << endl;
        st.insert(stoi(b));
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            used[i] = 1;
            rec(a, used, b + a[i]);
            used[i] = 0;
        }
    }
}

int main() {
    string a;
    cin >> a;
    n = a.size();
    for (ll i = 2; i * i <= 100000000; i++) {
        if (isPrime(i)) prime.push_back(i);
    }
    vector<int> used(n);
    rec(a, used, "");
    cout << st.size() << endl;
    return 0;
}