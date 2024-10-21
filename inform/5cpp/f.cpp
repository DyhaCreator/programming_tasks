#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string name;
    cin >> name;
    name.push_back(':');
    string s = "";
    char ch = 0;
    int ans = 0;
    while (ch != EOF) {
        if (ch != '\n') s.push_back(ch);
        ch = getchar();
        if (ch == '\n') {
            int found = 0;
            // cout << name << "---" << s << endl;
            if (name.size() <= s.size()) for (int i = 0; i < name.size(); i++) {
                // cout << name[i] << " " << s[i] << endl;
                if (name[i] != s[i]) found = 1;
            } else found = 1;
            if (!found) {
                ans++;
                // cout << s << endl;
            }
            s = "";
        }
    }
    cout << ans << endl;
    return 0;
}