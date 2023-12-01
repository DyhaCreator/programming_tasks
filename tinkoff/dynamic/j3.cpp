#include <iostream>
#include <vector>
#include <stack>
#define ll long long
#define sz .size()
using namespace std;

vector<int> left(vector<int>a) {
    vector<int>ans = vector<int>(a.size(), 0);
    stack<int>st;
    st.push(-1);
    for (int i = 0; i < a.size(); i++) {
        while (st.top() != -1 && a[st.top()] >= a[i]) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> right(vector<int>a) {
    vector<int>ans = vector<int>(a.size(), 0);
    stack<int>st;
    st.push(a.size());
    for (int i = a.size() - 1; i >= 0; i--) {
        while (st.top() != a.size() && a[st.top()] >= a[i]) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>map = vector<vector<int>>(n, vector<int>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }
    int maxs = 0;
    int maxx, maxy;
    vector<int>a = vector<int>(m, 0);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            a[x] += map[y][x];
            if (map[y][x] == 0) {
                a[x] = 0;
            }
        }
        /*for (auto x : a)
            cout << x << " ";
        cout << endl;*/
        vector<int>l = left(a);
        vector<int>r = right(a);
        /*for (auto x : l)
            cout << x << " ";
        cout << endl;
        for (auto x : r)
            cout << x << " ";
        cout << endl;*/
        for (int i = 0; i < m; i++) {
            int sx = (i - l[i]) + (r[i] - i) - 1;
            int sy = a[i];
            int py = y - a[i] + 1;
            int px = l[i] + 1;
            int s = min(sx, sy);
            if (s >= maxs) {
                maxs = s;
                maxx = px;
                maxy = py;
            }
        }
        //cout << "---" << endl;
    }
    cout << maxs << endl;
    cout << maxx + 1 << " " << maxy + 1 << endl;
    return 0;
}
/*

3 5
1 1 0 0 0
1 1 1 1 1
0 0 0 1 1

*/