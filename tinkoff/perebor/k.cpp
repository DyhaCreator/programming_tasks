#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int>nom;
int num, k;

void rec(int n, vector<int>money) {
    if (n == k) {
        cout << "Yes" << endl;
        ll sum = 0;
        for (int i = 0; i < num; i++) {
            sum += money[i];
        } 
        cout << sum << endl;
        for (int i = 0; i < num; i++) {
            if (money[i] == 1) {
                cout << nom[i] << " ";
            } else if (money[i] == 2) {
                cout << nom[i] << " " << nom[i] << " ";
            }
        }
        cout << endl;
        exit(0);
        return;
    }
    if (n >= k) {
        return;
    }
    for (int i = 0; i < num; i++) {
        if (money[i] <= 1) {
            money[i]++;
            rec(n + nom[i], money);
            money[i]--;
        }
    }
}

int main() {
    cin >> num >> k;
    nom = vector<int>(num);
    ll max_sum = 0;
    for (auto &x : nom) {
        cin >> x;
        max_sum += x * 2;
    }
    if (max_sum >= k) {
        rec(0, vector<int>(num));
        cout << "No" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}