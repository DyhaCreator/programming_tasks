#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            while (s[i] == s[i - 1] || (i < n - 1 && s[i] == s[i + 1]))
                s[i] = rand() % 26 + 'a';
        }
    }
    cout << s << endl;
    return 0;
}