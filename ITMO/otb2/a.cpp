#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

bool f1(bool a, bool b, bool c) {
    return a && c || !b && c;
}

bool f2(bool a, bool b, bool c) {
    return c || a && b;
}

bool f3(bool a, bool b, bool c) {
    return c || !a || !b;
}

bool f4(bool a, bool b, bool c) {
    return c || !(a || !b);
}

bool f5(bool a, bool b, bool c) {
    return a || !(c || !b);
}

bool f6(bool a, bool b, bool c) {
    return b || !(a || !c);
}

bool f7(bool a, bool b, bool c) {
    return (a || b) && (b || c);
}

bool f8(bool a, bool b, bool c) {
    return (!a && b) || (b && !c);
}

int main() {
    int mx = 0;
    int mx_ans = 0;
    for (int i = 0; i < (1 << 8); i++) {
        int cnt = 0;
        vector<int> ans(16, -1);
        cout << i << " ";
        if ((i & (1 << 0)) != 0) {
            for (int i = 0; i < (1 << 3); i++) {
                bool a = i & 1;
                bool b = i & 0b10;
                bool c = i & 0b100;
                if (f1(a, b, c) != ans[i]) {
                    if (ans[i] == -1) {
                        ans[i] = f1(a, b, c);
                    } else {
                        ans[i] = -2;
                    }
                }
            }
        }
        if ((i & (1 << 1)) != 0) {
            for (int i = 0; i < (1 << 3); i++) {
                bool a = i & 1;
                bool b = i & 0b10;
                bool c = i & 0b100;
                if (f2(a, b, c) != ans[i]) {
                    if (ans[i] == -1) {
                        ans[i] = f2(a, b, c);
                    } else {
                        ans[i] = -2;
                    }
                }
            }
        }
        if ((i & (1 << 2)) != 0) {
            for (int i = 0; i < (1 << 3); i++) {
                bool a = i & 1;
                bool b = i & 0b10;
                bool c = i & 0b100;
                if (f3(a, b, c) != ans[i]) {
                    if (ans[i] == -1) {
                        ans[i] = f3(a, b, c);
                    } else {
                        ans[i] = -2;
                    }
                }
            }
        }
        if ((i & (1 << 3)) != 0) {
            for (int i = 0; i < (1 << 3); i++) {
                bool a = i & 1;
                bool b = i & 0b10;
                bool c = i & 0b100;
                if (f4(a, b, c) != ans[i]) {
                    if (ans[i] == -1) {
                        ans[i] = f4(a, b, c);
                    } else {
                        ans[i] = -2;
                    }
                }
            }
        }
        if ((i & (1 << 4)) != 0) {
            for (int i = 0; i < (1 << 3); i++) {
                bool a = i & 1;
                bool b = i & 0b10;
                bool c = i & 0b100;
                if (f5(a, b, c) != ans[i]) {
                    if (ans[i] == -1) {
                        ans[i] = f5(a, b, c);
                    } else {
                        ans[i] = -2;
                    }
                }
            }
        }
        if ((i & (1 << 5)) != 0) {
            for (int i = 0; i < (1 << 3); i++) {
                bool a = i & 1;
                bool b = i & 0b10;
                bool c = i & 0b100;
                if (f6(a, b, c) != ans[i]) {
                    if (ans[i] == -1) {
                        ans[i] = f6(a, b, c);
                    } else {
                        ans[i] = -2;
                    }
                }
            }
        }
        if ((i & (1 << 6)) != 0) {
            for (int i = 0; i < (1 << 3); i++) {
                bool a = i & 1;
                bool b = i & 0b10;
                bool c = i & 0b100;
                if (f7(a, b, c) != ans[i]) {
                    if (ans[i] == -1) {
                        ans[i] = f7(a, b, c);
                    } else {
                        ans[i] = -2;
                    }
                }
            }
        }
        if ((i & (1 << 7)) != 0) {
            for (int i = 0; i < (1 << 3); i++) {
                bool a = i & 1;
                bool b = i & 0b10;
                bool c = i & 0b100;
                if (f8(a, b, c) != ans[i]) {
                    if (ans[i] == -1) {
                        ans[i] = f8(a, b, c);
                    } else {
                        ans[i] = -2;
                    }
                }
            }
        }
        int len = 0;
        for (int j = 0; j < 8; j++) {
            if ((i & (1 << j)) != 0) {
                len++;
            }
        }
        if (len > 1) {
            for (auto &x : ans)
                cout << x << " ";
            cout << endl;
            int aa = 0;
            for (auto &x : ans) {
                if (x >= 0) {
                    aa++;
                }
            }
            // cout << aa << endl;
            if (aa >= mx_ans) {
                mx_ans = aa;
                mx = i;
            }
        }
    }
    cout << mx_ans << " " << mx << endl;
    return 0;
}