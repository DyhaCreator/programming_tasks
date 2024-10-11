#include <iostream>
#include <vector>
using namespace std;

void solve() {
    string s;
    cin >> s;
    if (s[s.size() - 1] == 'a') {
        cout << s << "b" << endl;   
    } else {
        cout << s << "a" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}