#include <iostream>
#include <vector>
using namespace std;

int main() {
string s;
getline(cin, s);
for (auto &x : s)
if (x == '!') cout << '.';
else cout << x;return 0;
}