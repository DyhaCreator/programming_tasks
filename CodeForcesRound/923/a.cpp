#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#define ll long long
#define INF 1000000007
#define prvec(vec) for(auto &x:vec)cout<<x<<" ";cout<<endl;
#define all(vec) vec.begin(),vec.end()
using namespace std;

void solveA() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int s = 0;
        while (s < n && str[s] == 'W') {
            s++;
        }
        int f = n - 1;
        while (f >= s && str[f] == 'W') {
            f--;
        }

        cout << f - s + 1 << endl;
    }
}

void solveB() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        vector<int> count(26);
        for (int i = 0; i < n; i++) {
            int index = 0;
            while (index < 26 && count[index] != a[i]) {
                index++;
            }
            count[index]++;
            cout << char(index + 'a');
        }
        cout << endl;
    }
}

void solveC() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int n, m, k;
        cin >> n >> m >> k;
        set<int> st;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            st.insert(x);
        }
        vector<int> a = {};
        for (auto &x : st)
            a.push_back(x);
        set<int> st2;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            st2.insert(x);
        }
        vector<int> b = {};
        for (auto &x : st2)
            b.push_back(x);
        n = a.size();
        m = b.size();


        /*for (auto &x : a)
            cout << x << " ";
        cout << endl;
        for (auto &x : b)
            cout << x << " ";
        cout << endl;*/
        
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;

        int indexa = 0;
        int indexb = 0;
        int indexCount = 0;
        bool find = false;
        for (int indexCount = 0; indexCount < k; indexCount++) {
            // cout << count1 << " " << count2 << " " << count3 << endl;
            if (indexa < n && indexb < m && a[indexa] == indexCount + 1 && b[indexb] == indexCount + 1) {
                count3++;
                indexa++;
                indexb++;
            } else if (indexa < n && a[indexa] == indexCount + 1) {
                count1++;
                indexa++;
            } else if (indexb < m && b[indexb] == indexCount + 1) {
                count2++;
                indexb++;
            } else {
                cout << "NO" << endl;
                find = true;
                break;
            }
        }

        if (find == false) {
            // cout << count1 << " " << count2 << " " << count3 << endl;
            if (count1 == count2 && count3 % 2 == 0) {
                cout << "YES" << endl;
            } else if (count3 >= max(count1, count2) - min(count1, count2) && 
                      (count3 - max(count1, count2) - min(count1, count2)) % 2 == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}

int main() {
    solveC();
    return 0;
}