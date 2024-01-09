#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    set<string>st;
    map<string, int>mp;
    vector<string>names = vector<string>(n);
    vector<int>scores = vector<int>(n);
    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cin >> name >> score;
        st.insert(name);
        mp[name] += score;
        names[i] = name;
        scores[i] = score;
    }
    int maxScore = -1000000000;
    for (auto x : st)
        if (mp[x] > maxScore)
            maxScore = mp[x];
    map<string, int>mp2;
    for (int i = 0; i < n; i++) {
        if (mp[names[i]] == maxScore) {
            mp2[names[i]] += scores[i];
            if (mp2[names[i]] >= maxScore) {
                cout << names[i] << endl;
                return 0;
            }
        }
    }

    return 0;
}