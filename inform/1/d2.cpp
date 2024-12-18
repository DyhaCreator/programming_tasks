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
            if (map[i] == 'L' && i > 0 && map[i - 1] == '.') {
                map[i] = '.';
                map[i - 1] = 'L';
            } else if (map[i] == 'L' && i > 1 && map[i - 2] == '.' && map[i - 1] == 'R') {
                map[i] = '.';
                map[i - 2] = 'L';
            }
        }
        cout << map << endl;
        for (int i = n - 1; i >= 0; i--) {  
            if (map[i] == 'R' && i < n - 1 && map[i + 1] == '.') {
                map[i] = '.';
                map[i + 1] = 'R';
            } else if (map[i] == 'R' && i < n - 2 && map[i + 2] == '.' && map[i + 1] == 'L') {
                map[i] = '.';
                map[i + 2] = 'R';
            }
        }
        cout << map << endl;
        int k = 0;
        for (int i = 0; i < n - 1; i++) {
            if (map[i] == 'R' && map[i + 1] != 'R') {
                k++;
            }
        }
        for (int i = n - 1; i > 0; i--) {
            if (map[i] == 'L' && map[i - 1] != 'L') {
                k++;
            }
        }
        if (k == 0)
            break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}