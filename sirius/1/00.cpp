#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> vec;
    for (ll i = 0; i <= n; i++) {
        vec.push_back(i * i);
    }
    for (ll i = 0; i * i * i <= n * n; i++) {
        vec.push_back(i * i * i);
    }
    sort(vec.begin(), vec.end());
    /*for (auto &x : vec)
        cout << x << " ";
    cout << endl;*/
    int index = 0;
    for (int i = 0; i < vec.size(); i++) {
        //cout << vec[i] << " ";
        if (index == n) {
            cout << vec[i] << endl;
            break;
        }
        index++;
        if (vec[i] == vec[i + 1]) i++;
    }
    cout << endl;
    return 0;
}