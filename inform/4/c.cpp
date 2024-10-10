#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string s;
    getline(cin, s);
    string ans = "";
    int f = 0;
    for (int i = 0; i < s.size(); i++) {
        if (f == 1 && s[i] != ':') ans.push_back(s[i]);
        if (s[i] == ':')
            f++;
    }
    cout << ans << endl;
    return 0;
}