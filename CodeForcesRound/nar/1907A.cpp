#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;
        string str2 = str;
        str2[0] = 'a';
        while (str2[0] <= 'h') {
            if (str2[0] != str[0]) {
                cout << str2 << endl;
            }
            str2[0]++;
        }
        str2 = str;
        str2[1] = '1';
        while (str2[1] <= '8') {
            if (str2[1] != str[1]) {
                cout << str2 << endl;
            }
            str2[1]
        }
    }
    return 0;
}