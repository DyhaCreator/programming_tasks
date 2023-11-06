#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#define ll long long
using namespace std;

struct part{
    string name;
    int h, w;
    part(string name, int h, int w){
        this->name = name;
        this->h = h;
        this->w = w;
    }
};
inline bool operator<(const part& lhs, const part& rhs)
{
    ll a = abs(180 - lhs.h);
    ll b = abs(180 - rhs.h);
    if (a != b) {
        return a < b;
    }
    a = abs(lhs.w - 75);
    b = abs(rhs.w - 75);
    if (a != b) {
        return a < b;
    }
    return lhs.name < rhs.name;
}

int main() {
    int n;
    cin >> n;
    vector<part>p = vector<part>();
    set<part>st;
    for (int i = 0; i < n; i++) {
        string name;
        int h, w;
        cin >> name >> h >> w;
        part a(name, h, w);
        st.insert(a);
    }
    for (auto a : st) {
        cout << a.name << endl;
    }
    return 0;
}

/*

10
George 195 110
Thomas 180 75
John 180 75
James 180 65
Andrew 165 110
Martin 170 70
William 180 77
Franklin 195 70
Benjamin 165 70
Theodore 165 80

*/