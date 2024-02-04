#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct stud{
    int r = -1, c = -1;
    int rl = -1, rr = -1;
    int cl = -1, cr = -1;
    bool sss = false;
    stud() {}
    stud(int rl, int rr, int cl, int cr) {
        this->rl = rl;
        this->rr = rr;
        this->cl = cl;
        this->cr = cr;
    }
};

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m, k, p;
        cin >> n >> m >> k >> p;
        vector<stud> stu(k);
        for (int j = 0; j < p; j++) {
            char w;
            int s, a, b;
            cin >> w >> s >> a >> b;
            s--;
            a--;
            b--;
            if (w == 'C') {
                stu[s].cl = a;
                stu[s].cr = b;
            } else {
                stu[s].rl = a;
                stu[s].rr = b;
            }
        }
        /*for (auto &x : stu) {
            cout << x.rl << " " << x.rr << " " << x.cl << " " << x.cr << endl;
        }*/
        int q;
        cin >> q;
        vector<vector<int>> map(n, vector<int>(m));
        for (int j = 0; j < q; j++) {
            string com;
            int s, r, c;
            cin >> com >> s >> r >> c;
            s--;
            r--;
            c--;
            if (map[r][c] == 0) {
                if (stu[s].r != -1) {
                    map[stu[s].r][stu[s].c] = 0;
                }
                map[r][c] = 1;
                stu[s].r = r;
                stu[s].c = c;
                if ((stu[s].rr == -1 || (r <= stu[s].rr && r >= stu[s].rl)) && 
                    (stu[s].cr == -1 || ((c <= stu[s].cr && c >= stu[s].cl)))) {
                    stu[s].sss = true;
                } else {
                    stu[s].sss = false;
                }
            }
        }
        int ans = 0;
        for (auto &x : stu) {
            if (x.sss == false) ans++;
        }
        cout << ans << endl;
        // cout << "-------" << endl;
    }
    return 0;
}