#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define ll long long
using namespace std;

struct color{
    int r, g, b;
    color() {}
    color(int r, int g, int b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }
    bool operator==(color &b) {
        if (this->r == b.r && this->g == b.g && this->b == b.b) {
            return true;
        }
        return false;
    }
    bool operator<(color &b) {
        return this->r < b.r;
    }
};

bool f(vector<color> un, color n) {
    for (auto &x : un) {
        if (n == x) return false;
    }
    return true;
}

int main() {
    vector<color> un = {};
    set<color> st;

    vector<vector<vector<int>>> mp(256, vector<vector<int>>(256, vector<int>(256)));
    for (int r = 0; r < 256; r++) {
        for (int g = 0; g < 256; g++) {
            cout << g << " " << un.size() << endl;
            for (int b = 0; b < 256; b++) {
                color n;
                
                if (r % 2 == 0 && g % 2 == 0 && b % 2 == 0) {
                    n = (color(r, g, b));
                } else if (r % 2 == 1 && g % 2 == 1 && b % 2 == 1) {
                    n = (color(r, g, b));
                }
                if (r % 2 == 0 && g % 2 == 0 && b % 2 == 1) {
                    n = (color(r, g, b - 1));
                }
                if (r % 2 == 0 && g % 2 == 1 && b % 2 == 0) {
                    n = (color(r, g - 1, b));
                }
                if (r % 2 == 1 && g % 2 == 0 && b % 2 == 0) {
                    n = (color(r - 1, g, b));
                }
                if (r % 2 == 0 && g % 2 == 1 && b % 2 == 1) {
                    n = (color(r + 1, g, b));
                }
                if (r % 2 == 1 && g % 2 == 1 && b % 2 == 0) {
                    n = (color(r, g, b + 1));
                }
                if (r % 2 == 1 && g % 2 == 0 && b % 2 == 1) {
                    n = (color(r, g + 1, b));
                }
                // cout << g << " " << un.size() << endl;
                // cout << n.r << " " << n.g << " " << n.b << endl;
                if (mp[n.r][n.g][n.b] == 0) {
                    un.push_back(n);
                    mp[n.r][n.g][n.b] = 1;
                }
                // st.insert(n);
            }
        }
    }
    unique(un.begin(), un.end());
    cout << un.size() << endl;
    return 0;
}

/*

16581375
по 24 бита на пиксель

4194304
по 22 бита на пиксель



*/