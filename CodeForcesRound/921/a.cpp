#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        string str = "";
        for (int j = 0; j < n; j++) {
            char ch = 'a';
            for (int v = 0; v < k; v++) {
                str.push_back(ch);
                ch++;
            }
        }
        cout << str << endl;
    }
    return 0;
}