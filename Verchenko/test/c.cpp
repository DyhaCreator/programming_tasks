#include <iostream>
using namespace std;

void get(int key, int step) {
    string s = "cieoserrhlutncj ";
    int size = s.size();
    for (int i = 0; i < key * step; i += step, step++) {
        cout << s[i % size];
    }
    cout << endl;
}

int main(){
    for (int i = 1; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            get(i, j);
        }
    }
    return 0;
}