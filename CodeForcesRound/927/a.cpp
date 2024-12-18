#include <iostream>
#define ll long long    
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string v;
        cin >> v;
        int k = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] == '@') {
                k++;
            }
            if (j < n - 1 && v[j] == '*' && v[j + 1] == '*') {
                break;
            }
        }
        cout << k << endl;
    }
    return 0;
}