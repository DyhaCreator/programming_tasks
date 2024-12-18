#include <iostream>
#include <string>
#include <map>
#include <set>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        string s;
        cin >> a >> s;
        map<char, int>mp;
        set<char>st;
        for (int j = 0; j < s.size(); j++) {
            st.insert(s[j]);
            mp[s[j]]++;
        }
        int ans = 0;
        for (auto x : st) {
            if (mp[x] > x - 'A') {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}