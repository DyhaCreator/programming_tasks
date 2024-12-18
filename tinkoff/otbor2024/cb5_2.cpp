#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
using ll = long long;

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

    set<vector<char>> st;
    map<vector<char>, int> cnt;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        // cout << str << endl;
        vector<char> ans = {};

        for (auto &x : str) {
            if (x != '-') {
                if (num[x] != 0) ans.push_back(num[x]);
                else ans.push_back(x);
            }
        }
        ans.insert(ans.begin() + 3, '-');
        st.insert(ans);
        cnt[ans]++;
    }

    int c = 0;
    for (auto &x : st) {
        if (cnt[x] > 1) {
            for (auto &y : x)
                cout << y;
            cout << " " << cnt[x] << endl;
            c++;
        }
    }
    if (c == 0) cout << "No duplicates." << endl;
    return 0;
}