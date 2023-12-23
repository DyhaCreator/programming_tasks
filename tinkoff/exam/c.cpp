#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    string nameMax = "";
    int max = 0;
    for (int i = 0; i < n; i++) {
        int a;
        string name, co;
        cin >> a >> name >> co;
        if (co == "Russia" && a > max) {
            max = a;
            nameMax = name;
        }
    }
    cout << nameMax << endl;

    return 0;
}