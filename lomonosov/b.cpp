#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#define ll long long
using namespace std;

int main() {
    //clock_t start = clock();
    int n;
    cin >> n;
    vector<float>a = vector<float>(n);
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        string num = "";
        char c;
        string numbers = "0123456789";
        for (int j = 0; j < str.size(); j++) {
            if (numbers.find(str[j]) != string::npos) {
                num += str[j];
            } else {
                float index;
                if (str[j] == 'a') index = 0.01;
                else if (str[j] == 'b') index = 0.05;
                else if (str[j] == 'c') index = 0.1;
                else if (str[j] == 'd') index = 0.5;
                else if (str[j] == 'e') index = 1.0;
                else if (str[j] == 'f') index = 2.0;
                else if (str[j] == 'g') index = 5.0;
                else if (str[j] == 'h') index = 10.0;
                else if (str[j] == 'i') index = 25.0;
                a[i] += stoi(num) * index;
                num = "";
            }
        }
    }
    /*for (auto x : a)
        cout << x << endl;*/
    int max_k = 0;
    int max_l = 0;
    for (int k = 0; k < n - 1; k++) {
        for (int l = k; l < n; l++) {
            if (abs(a[l] - a[k]) > abs(a[max_l] - a[max_k])) {
                max_k = k;
                max_l = l;
            }
        }
    }
    cout << max_k + 1 << endl;
    cout << max_l + 1 << endl;
    //printf("%.2f sec\n", (float)(clock() - start)/CLOCKS_PER_SEC);
    return 0;
}