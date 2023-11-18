#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int main() {
    string word1, word2;
    cin >> word1 >> word2;
    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());
    if (word1 == word2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}