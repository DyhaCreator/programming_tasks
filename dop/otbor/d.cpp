#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string str;
    cin >> str;
    string et = "hello";
    int index = 0;
    for (int i = 0; i < str.size(); i++) {
        if (index < 5 && str[i] == et[index])
            index++;
    if (index == 5) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}