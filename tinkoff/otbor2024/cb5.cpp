#include <iostream>
#include <vector>
#include <map>
#include <set>
using ll = long long;
using namespace std;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    map<char, char> num;
    num['A'] = '2';
    num['B'] = '2';
    num['C'] = '2';
    
    num['D'] = '3';
    num['E'] = '3';
    num['F'] = '3';
    
    num['G'] = '4';
    num['H'] = '4';
    num['I'] = '4';
    
    num['J'] = '5';
    num['K'] = '5';
    num['L'] = '5';
    
    num['M'] = '6';
    num['N'] = '6';
    num['O'] = '6';
    
    num['P'] = '7';
    num['R'] = '7';
    num['S'] = '7';
    
    num['T'] = '8';
    num['U'] = '8';
    num['V'] = '8';
    
    num['W'] = '9';
    num['X'] = '9';
    num['Y'] = '9';
    
    set<string> st;
    map<string, int> cnt;
    string str;
    getline(cin, str);

    for (int i = 0; i < n; i++) {
        getline(cin, str);
        // cout << str << endl;
        string ans = "";
        for (auto &x : str) {
            if (x != '-') {
                if (x > 48 && x < 48 + 10) ans.push_back(x);
                else ans.push_back(num[x]);
            }
        }
        ans.insert(3, "-");
        st.insert(ans);
        cnt[ans]++;
    }
    /*cout << endl;
    for (auto &x : st) {
        for (auto &y : x)
            cout << y;
        cout << endl;
        for (auto &y : x) {
            cout << int(y) << " ";
        }
        cout << endl;
    }*/
    int c = 0;
    for (auto &x : st) {
        if (cnt[x] > 1) {
            cout << x << " " << cnt[x] << endl;
            c++;
        }
    }
    if (c == 0) cout << "No duplicates." << endl;
    return 0;
}