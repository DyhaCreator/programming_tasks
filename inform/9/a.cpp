#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    map<string, char> mp = {
        {"1010", 'a'},
        {"010000", 'b'},
        {"00100", 'c'},
        {"00101", 'd'},
        {"011", 'e'},
        {"100100", 'f'},
        {"110100", 'g'},
        {"10011", 'h'},
        {"1011", 'i'},
        {"010011110", 'j'},
        {"0100110", 'k'},
        {"11011", 'l'},
        {"00011", 'm'},
        {"0101", 'n'},
        {"1000", 'o'},
        {"110101", 'p'},
        {"0100111110", 'q'},
        {"0011", 'r'},
        {"0000", 's'},
        {"1100", 't'},
        {"00010", 'u'},
        {"010010", 'v'},
        {"010001", 'w'},
        {"01001110", 'x'},
        {"100101", 'y'},
        {"0100111111", 'z'},
        {"111", '_'}
    };
    string a;
    cin >> a;
    string th = "";
    string ans = "";
    int n = a.size();
    for (int i = 0; i < n; i++) {
        th.push_back(a[i]);
        if (mp[th] != 0) {
            ans.push_back(mp[th]);
            th = "";
        }
    }
    if (th.size() > 0) {
        cout << "incorrect" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}