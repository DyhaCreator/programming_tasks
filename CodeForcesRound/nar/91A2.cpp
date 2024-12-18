#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    int ans = 0;
    int index = 0;
    while (index < str2.size()) {
        int g = 0;
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] == str2[index]) {
                index++;
                g++;
            }
            if (index == str2.size()) {
                break;
            }
        }
        if (g == 0) {
            cout << -1 << endl;
            return 0;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}