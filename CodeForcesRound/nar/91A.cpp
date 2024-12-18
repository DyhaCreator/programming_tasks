#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int div(int a, int b) {
    return (a + b - 1) / b;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    vector<int>a(26);
    vector<int>b(26);
    for (auto &x : str1)
        a[x - 'a']++;
    for (auto &x : str2)
        b[x - 'a']++;
    for (auto &x : a)
        cout << x << " ";
    cout << endl;
    for (auto &x : b)
        cout << x << " ";
    cout << endl;
    for (int i = 0; i < 26; i++) {
        if (a[i] > 0 && b[i] == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    int max = 1;
    for (int i = 0; i < 26; i++) {
        if (div(a[i], b[i]) > max) {
            max = div(a[i], b[i]);
        }
    }
    cout << 
    return 0;
}