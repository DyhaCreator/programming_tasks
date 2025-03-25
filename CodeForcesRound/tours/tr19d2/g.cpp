#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<int> str(n);
    vector<int> stolb(m);
    for (auto &x : v)
        cin >> x;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (v[y][x] != '.') {
                str[y]++;
                stolb[x]++;
            }
        }
    }
    for (int i : stolb){
        if(i%2!=0){
            cout << "-1\n";
            return 0;
        }
    }
    cout << "peredos" << endl;
    for(int i : str){
        if(i%2!=0){
            cout << -1 << "\n";
        }
    }
    for (auto &x : str)
        cout << x << " ";
    cout << endl;
    for (auto &x : stolb)
        cout << x << " ";
    cout << endl;

    vector<int> str1(n);
    vector<int> stolb1(m);
    vector<vector<char>> ans(n + 1, vector<char> (m + 1));
    cout << 111 << endl;
    for(int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            if(v[i][j] == '.'){
                ans[i][j] ='.';
            }
            else if(ans[i][j] == 'B' || ans[i][j] == 'W'){
                continue;
            }
            else if(str1[i] + 1 <= str[i] / 2){
                if(v[i][j] == 'L'){
                    ans[i][j+1] = 'W';
                    ans[i][j] = 'B';\
                    str1[i]++;
                    stolb1[j]++;
                }
                else{
                    ans[i+1][j] = 'W';
                    ans[i][j] = 'B';
                    stolb1[j]++;
                    str1[i]++;
                }
            }
            else{
                if(v[i][j] == 'L'){
                    ans[i][j+1] = 'B';
                    ans[i][j] = 'W';\
                    str1[i]++;
                    stolb1[j+1]++;
                }
                else{
                    ans[i+1][j] = 'B';
                    ans[i][j] = 'W';
                    stolb1[j]++;
                    str1[i+1]++;
                }
            }
        }

    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << ans[i][j];
        }
        cout << "\n";
    }
}