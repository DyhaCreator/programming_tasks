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
        while (str2[0] > 'a') {
            str2[0]--;
            cout << str2[0] << endl;
        }
    }
    return 0;
}