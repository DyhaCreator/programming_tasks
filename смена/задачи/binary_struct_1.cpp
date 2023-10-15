#include <iostream>
#include <vector>
#include <cmath>

struct Struct{
    std::vector<int>all = std::vector<int>();

    Struct(){}
    Struct(std::vector<int>a, int m){
        int sz = 1;
        while(sz < a.size())
            sz*=2;
        all.resize(sz * 2 - 1, 0);
        for(int i = 0; i < a.size(); i++){
            all[sz + i - 1] = a[i];
        }
        update(0, m);
    }

    void update(int v, int mode){
        if(v >= all.size() / 2)
            return;
        update(v * 2 + 1, mode);
        update(v * 2 + 2, mode);
        if(mode == 0){
            all[v] = all[v * 2 + 1] + all[v * 2 + 2];
        }
        if(mode == 1){
            all[v] = std::max(all[v * 2 + 1], all[v * 2 + 2]);
        }
    }

    void set(int i, int v){
        all[i + all.size() / 2] = v;
        update(0, 0);
    }

    int sum(int L, int R){
        L += all.size() / 2;
        R += all.size() / 2;
        int ans = 0;
        while(L <= R){
            if(L % 2 != 0)ans += all[L - 1];
            if(R % 2 == 0)ans += all[R - 1];
            L = (L + 1) / 2;
            R = (R - 1) / 2;
        }
        return ans;
    }

    int max_(int L, int R){
        L += all.size() / 2;
        R += all.size() / 2;
        int ans = 0;
        while(L <= R){
            if(L % 2 != 0)ans = std::max(all[L - 1], ans);
            if(R % 2 == 0)ans = std::max(all[R - 1], ans);
            L = (L + 1) / 2;
            R = (R - 1) / 2;
        }
        return ans;
    }
};

int main(){
    std::vector<int>down = std::vector<int>();
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        std::cin >> num;
        down.push_back(num);
    }

    Struct *stru = new Struct(down, 1);

    //std::cout << stru -> sum(2,3) << std::endl;
    std::cout << stru -> max_(2, 3) << std::endl;

    for(int i = 0; i < stru -> all.size(); i++){
        std::cout << stru -> all[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}