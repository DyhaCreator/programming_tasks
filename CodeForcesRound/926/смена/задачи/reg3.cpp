#include <iostream>
#include <vector>

int main(){
    //10 4
    //1 2 3 9 1 7 3 2 1 6
    std::vector<int>pref = std::vector<int>(1);
    std::vector<int>all = std::vector<int>();
    int n, k;
    std::cin >> n >> k;
    for(int i = 0; i < n; i++){
        int num;
        std::cin >> num;
        pref.push_back(pref[pref.size()-1] + num);
        all.push_back(num);
    }
    pref.erase(pref.begin());
    int max = 0, maxId = 0;
    for(int i = 0; i <= n - k; i++){
        //std::cout << pref[i + k - 1] - pref[i - 1] << std::endl;
        if(pref[i + k - 1] - pref[i - 1] > max){
            max = pref[i + k - 1] - pref[i - 1];
            maxId = i;
        }
    }
    for(int i = 0; i < k; i++){
        all.erase(all.begin() + maxId);
    }
    pref.resize(all.size());
    for(int i = 0; i < pref.size(); i++){

        pref[i] = 0;
        pref[i] = pref[i - 1] + all[i];
    }
    
    max = 0;
    for(int i = 0; i <= n - (k * 2); i++){
        if(!((i >= maxId && i < maxId + k) || i + k < maxId)){
            //std::cout << pref[i + k - 1] - pref[i - 1] << std::endl;
            if(pref[i + k - 1] - pref[i - 1] > max){
                max = pref[i + k - 1] - pref[i - 1];
            }
        }
    }
    std::cout << max << std::endl;
    return 0;
}