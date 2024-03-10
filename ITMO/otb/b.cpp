#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int countB(vector<int> v) {
    int ans = 0;
    int count = 1;
    while (count > 0) {
        count = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] > v[i + 1]) {
                int buffer = v[i];
                v[i] = v[i + 1];
                v[i + 1] = buffer;
                ans++;
                count++;
            }
        }
    }
    return ans;
}

int ansForM = 0;

void countM(vector<int> &v) {
    if (v.size() > 1) {
        vector<int> l = {};
        vector<int> r = {};
        for (int i = 0; i < (v.size() + 1) / 2; i++) {
            l.push_back(v[i]);
            // cout << v[i] << " ";
        }
        // cout << endl;
        for (int i = (v.size() + 1) / 2; i < v.size(); i++) {
            r.push_back(v[i]);
            // cout << v[i] << " ";
        }
        // cout << endl;
        countM(l);
        countM(r);
        int ff = 0;
        int j = 0;
        vector<int> ans = {};
        for (int i = 0; i < l.size(); i++) {
            while (j < r.size() && r[j] < l[i]) {
                ff = 1;
                ans.push_back(r[i]);
                j++;
            }
            ans.push_back(l[i]);
        }
        if (ff) {
            ansForM++;
        }
        v = ans;
        /*for (auto &x : v)
            cout << x << " ";
        cout << endl;*/
    }
}

int main() {
    vector<int> a = {};
    for (int i = 1; i < 129; i++) {
        a.push_back(i);
        cout << i << " ";
    }
    for (int i = 256; i > 128; i--) {
        a.push_back(i);
        cout << i << " ";
    }
    cout << endl;
    cout << countB(a) << endl;
    countM(a);
    cout << ansForM << endl;
    return 0;
}