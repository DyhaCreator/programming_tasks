#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define ll long long
using namespace std;

struct comand{
    string r;
    ll n;
    comand() {}
    comand(string r, int n) {
        this->r = r;
        this->n = n;
    }
};

bool isPrime(int num, vector<int>&prime) {
    for (auto x : prime)
        if (num % x == 0) return false;
    return true;
}

int main() {
    int l, N;
    cin >> l >> N;
    vector<comand>cmds = vector<comand>();
    ll maxS = 0;
    int d = 0;
    ll x = 0, y = 0;
    ll testL = l;
    for (int i = 0; i < N; i++) {
        comand c = comand();
        cin >> c.r >> c.n;
        cmds.push_back(c);
        if (c.r == "Left") {
            d--;
            if (d < 0) {
                d = 3;
            }
        } else {
            d++;
            if (d > 3) {
                d = 0;
            }
        }
        if (d == 0 && testL >= c.n * c.n) {
            y += c.n;
            testL -= c.n * c.n;
        } else if (d == 1 && testL >= c.n * c.n) {
            x += c.n;
            testL -= c.n * c.n;
        } else if (d == 2 && testL >= c.n * c.n) {
            y -= c.n;
            testL -= c.n * c.n;
        } else if (d == 3 && testL >= c.n * c.n) {
            x -= c.n;
            testL -= c.n * c.n;
        }
        maxS = std::max(maxS, abs(x) + abs(y));
    }
    //cout << maxS << endl;
    vector<int>prime = vector<int>();
    vector<int>count = vector<int>(2, 0);
    for (int i = 2; i <= maxS; i++) {
        count.push_back(0);
        count[count.size() - 1] = count[count.size() - 2];
        if (isPrime(i, prime)) {
            prime.push_back(i);
            //cout << i << " ";
            count[count.size() - 1]++;
        }
    }
    /*cout << endl;
    for (auto x : count)
        cout << x << " ";
    cout << endl;*/

    ll ANS = 0;
    d = 0;
    x = 0, y = 0;
    for (int i = 0; i < cmds.size(); i++) {
        if (cmds[i].r == "Left") {
            d--;
            if (d < 0) {
                d = 3;
            }
        } else {
            d++;
            if (d > 3) {
                d = 0;
            }
        }
        //cout << d << " ";
        if (d == 0 && l >= cmds[i].n * cmds[i].n) {
            ll lastY = y;
            y += cmds[i].n;
            if (lastY < 0 && y > 0) {
                ANS += count[abs(lastY) + abs(x)] - count[abs(x)] + count[abs(y) + abs(x)] - count[abs(x)];
            } else {
                ANS += count[max(abs(y), abs(lastY)) + abs(x)] - count[min(abs(y), abs(lastY)) + abs(x)];
            }
            //cout << count[abs(lastY) + abs(x)] + count[abs(y) + abs(x)] << " " << abs(lastY) + abs(x) << " " << abs(y) + abs(x) << "  ";
            //cout << "b" << count[max(abs(y), abs(lastY)) + abs(x)] - count[min(abs(y), abs(lastY)) + abs(x)] << " " << max(abs(y), abs(lastY)) + abs(x) << " " << min(abs(y), abs(lastY)) + abs(x) << "  ";
            l -= cmds[i].n * cmds[i].n;
        } else if (d == 1 && l >= cmds[i].n * cmds[i].n) {
            ll lastX = x;
            x += cmds[i].n;
            if (lastX < 0 && x > 0) {
                ANS += count[abs(lastX) + abs(y)] - count[abs(y)] + count[abs(x) + abs(y)] - count[abs(y)];
            } else {
                ANS += count[max(abs(x), abs(lastX)) + abs(y)] - count[min(abs(x), abs(lastX)) + abs(y)];
            }
            l -= cmds[i].n * cmds[i].n;
        } else if (d == 2 && l >= cmds[i].n * cmds[i].n) {
            ll lastY = y;
            y -= cmds[i].n;
            if (lastY > 0 && y < 0) {
                ANS += count[abs(lastY) + abs(x)] - count[abs(x)] + count[abs(y) + abs(x)] - count[abs(x)];
            } else {
                ANS += count[max(abs(y), abs(lastY)) + abs(x)] - count[min(abs(y), abs(lastY)) + abs(x)];
            }
            //cout << count[abs(lastY) + abs(x)] + count[abs(y) + abs(x)] << " " << abs(lastY) + abs(x) << " " << abs(y) + abs(x) << "  ";
            l -= cmds[i].n * cmds[i].n;
        } else if (d == 3 && l >= cmds[i].n * cmds[i].n) {
            ll lastX = x;
            x -= cmds[i].n;
            if (lastX > 0 && x < 0) {
                ANS += count[abs(lastX) + abs(y)] - count[abs(y)] + count[abs(x) + abs(y)] - count[abs(y)];
            } else {
                ANS += count[max(abs(x), abs(lastX)) + abs(y)] - count[min(abs(x), abs(lastX)) + abs(y)];
                //cout << "b" << count[max(abs(x), abs(lastX)) + abs(y)] - count[min(abs(x), abs(lastX)) + abs(y)] << " " << max(abs(x), abs(lastX)) + abs(y) << " " << min(abs(x), abs(lastX)) + abs(y) << "  ";
            }
            l -= cmds[i].n * cmds[i].n;
        }
        //cout << ANS << "\n";
    }
    cout << ANS << endl;
    return 0;
}

/*

100 4
Right 2
Left 2
Right 1
Right 3

*/