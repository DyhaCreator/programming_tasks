#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct qw{
    int l, r, t, v;
    qw(){}
    qw(int l, int r, int t, int v) {
        this->l = l;
        this->r = r;
        this->t = t;
        this->v = v;
    }
};

struct time_moment{
    int t;
    vector<int>moment;
    time_moment() {}
    time_moment(int t, vector<int>moment) {
        this->t = t;
        this->moment = moment;
    }
};

bool compt(qw a, qw b) {
    return a.t < b.t;
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<qw>q = vector<qw>();
    for (int i = 0; i < n; i++) {
        int l, r, t, v;
        cin >> l >> r >> t >> v;
        qw a = qw(l - 1, r - 1, t, v);
        q.push_back(a);
    }
    clock_t start = clock();
    sort(q.begin(), q.end(), compt);
    /*for (auto x : q)
        cout << x.l << " " << x.r << " " << x.t << " " << x.v << endl;*/

    vector<time_moment>time_line = vector<time_moment>();
    time_line.push_back(time_moment(-1, vector<int>(k)));

    for (int i = 0; i < q.size(); i++) {
        if (q[i].t != time_line[time_line.size() - 1].t) {
            vector<int>new_time = time_line[time_line.size()-1].moment;
            new_time[q[i].l] += q[i].v;
            new_time[q[i].r + 1] -= q[i].v;
            time_line.push_back(time_moment(q[i].t, new_time));
        } else {
            time_line[time_line.size() - 1].moment[q[i].l] += q[i].v;
            time_line[time_line.size() - 1].moment[q[i].r + 1] -= q[i].v;
        }
    }
    /*for (int i = 0; i < time_line.size(); i++) {
        for (auto x : time_line[i].moment)
            cout << x << " ";
        cout << endl;
    }*/

    vector<time_moment>out_time_line = vector<time_moment>(time_line.size());

    for (int i = 0; i < time_line.size(); i++) {
        vector<int>moment = vector<int>(time_line[i].moment.size() + 1, 0);
        for (int j = 1; j <= time_line[i].moment.size(); j++) {
            moment[j] = moment[j - 1] + time_line[i].moment[j - 1];
            //cout << moment[j] << " ";
        }
        //cout << endl;
        out_time_line[i].moment = moment;
        out_time_line[i].t = time_line[i].t;
    }

    vector<time_moment>pref_time_line = vector<time_moment>(out_time_line.size());

    for (int i = 0; i < out_time_line.size(); i++) {
        vector<int>moment = vector<int>(out_time_line[i].moment.size(), 0);
        for (int j = 1; j < out_time_line[i].moment.size(); j++) {
            moment[j] = moment[j - 1] + out_time_line[i].moment[j];
            //cout << moment[j] << " ";
        }
        //cout << endl;
        pref_time_line[i].moment = moment;
        pref_time_line[i].t = out_time_line[i].t;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r, t;
        cin >> l >> r >> t;
        int index = 0;
        while (index < pref_time_line.size() - 1 && pref_time_line[index].t < t) {
            index++;
        }
        cout << pref_time_line[index].moment[r] - pref_time_line[index].moment[l - 1] << endl; 
    }
    printf("%.6f sec\n", (float)(clock() - start)/CLOCKS_PER_SEC);
    return 0;
}