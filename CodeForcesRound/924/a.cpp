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
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        bool find = false;
        if (a % 2 == 0 && b != a / 2) {
            find = true;
        }
        if (b % 2 == 0 && a != b / 2) {
            find = true;
        }
        if (find) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

void solveB() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        set<int> st;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            st.insert(x);
        }

        vector<int> vec = {};
        for (auto &x : st)
            vec.push_back(x);

        /*for (auto &x : vec)
            cout << x << " ";
        cout << endl;*/
        int ans = 0;
        int l = 0;
        for (int r = 0; r < vec.size(); r++) {
            while (vec[r] - vec[l] + 1 > n) {
                l++;
            }
            if (vec[r] - vec[l] + 1 <= n) {
                ans = std::max(r - l + 1, ans);
                // cout << l << " " << r << endl;
            }
        }
        cout << ans << endl;
    }
}

vector<int> prime = {};

bool isPrime(int n) {
    for (auto &x : prime) {
        if (n % x == 0) return false;
    }
    return true;
}

void solveC() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int n, k;
        cin >> n >> k;
        int a = n - k;
        int b = 

        for (int i = 2; i * i <= n * 2; i++) {

        }
    }
}

int main() {
    solveC();
    return 0;
}