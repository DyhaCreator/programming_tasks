#include <iostream>
#include <string>
#include <sstream>
#define ll long long
using namespace std;

int main() {
    char a, b;
    int c, d;
    cin >> a >> c >> b >> d;
    //cout << a << " " << b << " " << c << " " << d << endl; 
    int x = b - a;
    int y = d - c;
    //cout << x << " " << y << endl;
    string ans = "";
    stringstream ss(ans);
    int ansNum = 0;
    while (x != 0 || y != 0) {
        if (x > 0) {
            ss << "R";
            x--;
        } else if (x < 0) {
            ss << "L";
            x++;
        }
        if (y > 0) {
            ss << "U";
            y--;
        } else if (y < 0) {
            ss << "D";
            y++;
        }
        ss << endl;
        ansNum++;
    }
    cout << ansNum << endl;
    cout << ss.str();
    return 0;
}