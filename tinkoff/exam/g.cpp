#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct rule{
    string n1, n2;
    bool ab;
    rule() {}
    rule(string n1, bool ab, string n2) {
        this->n1 = n1;
        this->ab = ab;
        this->n2 = n2;
    }
};

string minStr = "";
vector<rule>rules = vector<rule>();
vector<string>namesOf = {"LeshaMaren", "Danya", "Vasya", "Dima", "Jenya", "LeshaVasil", "Ilia", "Gosha"};

bool f(vector<int>names) {
    for (int i = 0; i < 8; i++) {
        if (names[i] == 0) {
            return false;
        } 
    }
    return true;
}

bool f2(vector<string>names) {
    for (int i = 0; i < 8; i++) {
        for (auto r : rules) {
            if (r.n1 == names[i]) {
                if (!r.ab) {
                    if (find(names.begin(), names.begin() + i, r.n2) == names.begin() + i) {
                        return false;
                    }
                } else {
                    if (find(names.begin() + i, names.end(), r.n2) == names.end()) {
                        return false;
                    }
                }
            } else if (r.n2 == names[i]) {
                if (r.ab) {
                    if (find(names.begin(), names.begin() + i, r.n2) == names.begin() + i) {
                        return false;
                    }
                } else {
                    if (find(names.begin() + i, names.end(), r.n2) == names.end()) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void rec(vector<string>namesStrings, vector<int>names) {
    if (f(names)) {
        if (f2(namesStrings)) {
            string str = "";
            for (auto x : namesStrings) {
                str += x + " ";
            }
            if (minStr != "") {
                minStr = std::min(str, minStr);
            } else {
                minStr = str;
            }
        }
    }
    namesStrings.push_back("");
    for (int i = 0; i < 8; i++) {
        if (names[i] == 0) {
            names[i] = 1;
            namesStrings[namesStrings.size() - 1] = namesOf[i];
            rec(namesStrings, names);
            names[i] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string n1, ab, n2;
        cin >> n1 >> ab >> n2;
        rule r = rule(n1, ab == "before", n2);
        rules.push_back(r);
    }
    rec(vector<string>(), vector<int>(8, 0));
    cout << minStr << endl;
    return 0;
}