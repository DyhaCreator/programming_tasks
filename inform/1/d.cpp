#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string map;
    getline(cin, map);
    int n = map.size();
    int ans = 0;
    while (true) {
        for (int i = 0; i < n; i++) {
            if (map[i] == 'R') {
                if (i < n - 1 && map[i + 1] == '.') {
                    map[i + 1] = 'R';
                    map[i] = '.';
                    i++;
                } else if (i < n - 2 && map[i + 2] == '.') {
                    map[i + 2] = 'R';
                    map[i] = '.';
                }
            } else if (map[i] == 'L') {
                if (i > 0 && map[i - 1] == '.') {
                    map[i - 1] = 'L';
                    map[i] = '.';
                } else if (i > 1 && map[i - 2] == '.') {
                    map[i - 2] = 'L';
                    map[i] = '.';
                }
            }
            cout << map << endl;
        }
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (map[i] == 'R' && i < n - 1 && map[i + 1] != 'R') {
                k++;
            }
            if (map[i] == 'L' && i > 0 && map[i - 1] != 'L') {
                k++;
            }
        }
        cout << k << endl;
        if (k == 0) {
            break;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}