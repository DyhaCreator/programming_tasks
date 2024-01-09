#include <iostream>
#include <vector>
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
    vector<string>names = vector<string>(n);
    vector<int>scores = vector<int>(n);
    for (int i = 0; i < n; i++) {
        string name;
        ll score;
        cin >> name >> score;
        st.insert(name);
        mp[name] += score;
        names[i] = name;
        scores[i] = score;
    }
    vector<string>maxNames = vector<string>();
    for (auto x : st)
        if (mp[x] > mp[maxName])
            maxName = x;
    int maxScore = mp[maxName];
    for (auto x : st)
        if (mp[x] == maxScore) 
            maxNames.push_back(x);
    /*for (auto x : maxNames)
        cout << x << "\n";*/
    map<string, int>mp2;
    for (int i = 0; i < n; i++) {
        if (mp[names[i]] == maxScore) {
            mp2[names[i]] += scores[i];
            if (mp2[names[i]] == maxScore) {
                cout << names[i] << endl;
                return 0;
            }
        }
    }
    //cout << maxName << endl;
    return 0;
}