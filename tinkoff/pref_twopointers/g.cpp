#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll>vec = vector<ll>(n + 1);
    for (int i = 1; i < n + 1; i++) {
        int x;
        cin >> x;
        vec[i] = vec[i - 1] + x;
        //cout << vec[i] << " ";
    }
    //cout << endl;
    ll max_index = 0;
    ll min_index = 0;
    for (ll i = 0; i < n + 1; i++) {
        if (vec[i] > vec[max_index]) {
            max_index = i;
        }
    }
    for (ll i = 0; i < max_index; i++) {
        if (vec[i] <= vec[min_index]) {
            min_index = i;
        }
    }
    
    cout << min_index + 1 << " " << max_index << " " << vec[max_index] - vec[min_index] << endl;

    return 0;
}