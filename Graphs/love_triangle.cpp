#include <iostream>
#include <vector>
#define ll long long
using namespace std;

bool dfs(vector<int>&matrix, int n, vector<int>&visited, int num) {
    //cout << n << endl;
    visited[n] = num;
    if (visited[matrix[n]] == 0) {
        if (dfs(matrix, matrix[n], visited, num + 1)) {
            return true;
        }
    } else if (visited[matrix[n]] == num - 2) {
        return true;
    }
    visited[n] = -1000000000;
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int>matrix(n);
    for (auto &x : matrix) {
        cin >> x;
        x--;
    }
    vector<int>visited(n);
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (dfs(matrix, i, visited, 1)) {
                cout << "YES" << endl;
                return 0;
            } 
        }
    }
    cout << "NO" << endl;
    return 0;
}
/*
5
2 4 5 1 3
*/