#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string s;
    getline(cin, s);
    string ans = "";
    int found = 0;
    for (auto &x : s) {
        if (found == 1 && x != ':') ans.push_back(x);
        if (x == ':') found++;
    }
    cout << ans << endl;
    return 0;
}