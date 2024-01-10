#include <iostream>
#include <string>
#include <vector>
#include <set>
#define ll long long
using namespace std;

int f(int n, string str) {
    int ans = 0;
    set<char>st;
    for (int i = 0; i < n; i++) {
        st.insert(str[i]);
        ans += st.size();
        //cout << ans<< " ";
    }
    //cout << endl;
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        cout << f(n, str) << endl;
    }
    return 0;
}