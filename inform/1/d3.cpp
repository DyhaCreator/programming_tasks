#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int n;
map<string, vector<string>> g;
map<string, int> used;
vector<string> sorted = {};

int gen_g(int index, string str) {
    if (index == n) {
        string new_str = str;
        // cout << str << endl;
        g[str] = {};
        used[str] = INF;
        sorted.push_back(str);
        for (int i = 0; i < n - 1; i++) {
            if (str[i] != '.' && str[i + 1] == '.') {
                new_str[i + 1] = new_str[i];
                new_str[i] = '.';
                g[str].push_back(new_str);
            } else {
                int ind = i;
                while (ind < n - 2 && new_str[ind] != '.' && new_str[ind + 1] != '.' && new_str[ind + 2] == '.') {
                    new_str[ind + 2] = new_str[ind];
                    new_str[ind] = '.';
                    ind += 2;
                    g[str].push_back(new_str);
                }
            }
            // cout << new_str << endl;
            new_str = str;
        }
        for (int i = n - 1; i > 0; i--) {
            if (str[i] != '.' && str[i - 1] == '.') {
                new_str[i - 1] = new_str[i];
                new_str[i] = '.';
                g[str].push_back(new_str);
            } else {
                int ind = i;
                while (ind > 1 && new_str[ind] != '.' && new_str[ind - 1] != '.' && new_str[ind - 2] == '.') {
                    new_str[ind - 2] = new_str[ind];
                    new_str[ind] = '.';
                    ind -= 2;
                    g[str].push_back(new_str);
                }
            } 
            
            /*else if (str[i] == 'L' && str[i - 1] != '.' && i > 1 && str[i - 2] == '.') {
                new_str[i] = '.';
                new_str[i - 2] = 'L';
            }*/
            if (new_str != str) g[str].push_back(new_str);
            // cout << new_str << endl;
            new_str = str;
        }
        /*for (auto &x : g[str])
            cout << x << " ";
        cout << endl;*/
        // cout << endl;
        return 0;
    }
    str[index] = '.';
    gen_g(index + 1, str);
    str[index] = 'R';
    gen_g(index + 1, str);
    str[index] = 'L';
    gen_g(index + 1, str);
    return 0;
}

int main() {
    string str;
    getline(cin, str);
    n = str.size();
    string th = str;
    for (auto &x : th)
        x = '.';
    gen_g(0, th);
    queue<string> q;
    q.push(str);
    used[str] = 0;
    while (!q.empty()) {
        string num = q.front();
        q.pop();
        for (auto &x : g[num]) {
            if (used[x] == INF) {
                used[x] = used[num] + 1;
                q.push(x);
            }
        }
    }
    string end_str = str;
    for (auto &x : end_str)
        x = '.';
    int cntR = 0;
    int cntL = 0;
    for (auto &x : str) {
        if (x == 'R')
            cntR++;
        if (x == 'L')
            cntL++;
    }
    // cout << cntL << " " << cntR << endl;
    for (int i = 0; i < cntL; i++)
        end_str[i] = 'L';
    for (int i = n - 1; i > n - cntR - 1; i--)
        end_str[i] = 'R';
    /*cout << end_str << endl;
    for (auto &x : sorted)
        cout << x << " " << used[x] << endl;*/
    cout << used[end_str] << endl;
    return 0;
}