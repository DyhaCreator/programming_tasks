#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string a;
    getline(cin, a);
    vector<string> b = {""};
    for (auto &x : a) {
        if (x == ' ' && b.size() > 0 && b[b.size() - 1].size() > 0) {
            b.push_back("");
        } else if (x != ' ') {
            b[b.size() - 1].push_back(x);
        }
    }
    reverse(b.begin(), b.end());
    for (int i = 0; i < b.size() - 1; i++)
        cout << b[i] << " ";
    cout << b[b.size() - 1] << endl;
    return 0;
}