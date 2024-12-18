#include <iostream>
#include <string>
#include <set>
#include <map>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    set<string>st;
    map<string, ll>mp;
    string maxName = "";
    for (int i = 0; i < n; i++) {
        string name;
        ll score;
        cin >> name >> score;
        //st.insert(name);
        mp[name] += score;
        if (mp[name] > mp[maxName])
            maxName = name;
    }
    /*string maxName = "";
    for (auto x : st)
        if (mp[x] > mp[maxName])
            maxName = x;*/
    cout << maxName << endl;
    return 0;
}