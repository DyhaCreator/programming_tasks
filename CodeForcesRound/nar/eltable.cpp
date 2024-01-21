#include <iostream>
#include <sstream>
#include <string>
#define ll long long
using namespace std;

string f(int a) {
    string ans = "";
    while (a > 0) {
        ans += char(a % 27 + 65);
        a /= 27;
    }
    return ans;
}

int f2(string str) {
    int ans = 0;
    int n = 0;
    int nnn = 1;
    for (int i = str.size() - 1; i >= 0; i--) {
        ans += (str[i] - 64) * nnn;
        nnn *= 26;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        if (ch == 'R') {
            int a, b;
            cin >> a >> ch >> b;
            cout << f(b) << a << endl;
        } else {
            string str = "";
            str.push_back(ch);
            while (ch >= 65) {
                cin >> ch;
                if (ch < 65) {
                    str.push_back(' ');
                    str.push_back(ch);
                    break;
                } else {
                    str.push_back(ch);
                }
            }
            string str2;
            cin >> str2;
            str += str2;
            //cout << str << endl;
            string ab;
            stringstream ss(str);
            ss >> ab;
            //cout << ab << endl;
            int num;
            ss >> num;
            cout << "R" << num << "C" << f2(ab) << endl;
        }
    }
    return 0;
}