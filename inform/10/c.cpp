#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    setlocale(0, "");
    string s;
    cin >> s;
    cout << s << " ";
    string al = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    vector<int> ss = {};
    for (auto &x : s) {
        cout << x << " ";
        for (int i = 0; i < al.size(); i++) {
            
            if (al[i] == x) {
                ss.push_back(i);
            }
        }
    }
    for (auto &x : ss)
        cout << x << " ";
    cout << endl;
    for (int k = 0; k < al.size(); k++) {
        
    }
    return 0;
}