#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

int n, m;

vector<int> right(vector<int>a) {
    reverse(a.begin(), a.end());
    stack<int>st;
    stack<int>index;
    st.push(-1);
    index.push(-1);
    vector<int>ans = vector<int>();
    for (int i = 0; i < m; i++) {
        while (st.top() >= a[i]) {
            st.pop();
            index.pop();
        }
        ans.push_back(index.top());
        st.push(a[i]);
        index.push(m - i - 1);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> left(vector<int>a) {
    stack<int>st;
    stack<int>index;
    st.push(-1);
    index.push(-1);
    vector<int>ans = vector<int>();
    for (int i = 0; i < m; i++) {
        while (st.top() >= a[i]) {
            st.pop();
            index.pop();
        }
        ans.push_back(index.top());
        st.push(a[i]);
        index.push(i);
    }
    return ans;
}

int main() {
    cin >> n >> m;
    vector<vector<int >> a = vector<vector<int >> (n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    clock_t tStart = clock();
    ll max_ans = 0;
    vector<int>b = vector<int>(m);
    vector<int>ansR = vector<int>(m, -1);
    vector<int>ansL = vector<int>(m, -1);
    for (int y = 0; y < n; y++) {
        bool bf = false;
        for (int x = 0; x < m; x++) {
            if (a[y][x] == 0) {
                b[x]++;
            } else {
                b[x] = 0;
                bf = true;
            }
        }
        if (bf) {
            ansR = right(b);
            ansL = left(b);
        }
        ll max = 0;
        for (int i = 0; i < m; i++) {
            ll L = 0;
            if (ansR[i] == -1) {
                L += m - i - 1;
            } else {
                L += ansR[i] - i - 1;
            }
            if (ansL[i] == -1) {
                L += i + 1;
            } else {
                L += i - ansL[i];
            }
            if (L * b[i] > max) {
                max = L * b[i];
            }
            //cout << L * b[i] << " ";
        }
        //cout << endl;
        max_ans = std::max(max, max_ans);
    }
    cout << max_ans << endl;
    printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
/*

4 4
0 0 0 0
0 1 0 1
0 0 0 0
1 1 0 0

5 6
1 0 0 0 1 0
0 0 0 0 1 0
0 0 1 0 0 0
0 0 0 0 0 0
0 0 1 0 0 0

*/