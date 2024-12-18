#include <iostream>
#include <vector>
#include <set>
#include <map>
#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int>a = vector<int>(n);
    for (auto &x : a)
        cin >> x;
    set<int>st;
    map<int, int>mp;

    int ansL = 0, ansR = 1000000000;

    int l = 0;
    for (int r = 0; r < n; r++) {
        st.insert(a[r]);
        mp[a[r]]++;
        while (st.size() >= k) {
            if (st.size() == k) {
                if (r - l < ansR - ansL) {
                    //cout << "YES " << l << " " << r << endl;
                    ansL = l;
                    ansR = r;
                }
            }
            mp[a[l]]--;
            if (mp[a[l]] == 0) {
                st.erase(a[l]);
            }
            l++;
        }
    }
    if (ansL == 0 && ansR == 1000000000) {
        cout << -1 << endl;
    } else {
        cout << ansL + 1 << " " << ansR + 1 << endl;
    }
    return 0;
}