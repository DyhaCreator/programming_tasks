#include <iostream>
#include <vector>
#include <map>

bool sorted(std::vector<int>a){
    for(int i = 0; i < a.size(); i++){
        bool c = true;
        for(int j = 0; j < a.size() - 1; j++){
            int b = j + i;
            int b2 = j + i + 1;
            if(b > a.size() - 1){
                b -= a.size();
            }
            if(b2 > a.size() - 1){
                b2 -= a.size();
            }
            if(a[b] > a[b2]){
                c = false;
            }
            //std::cout << a[b] << " ";
        }
        //std::cout << c << std::endl;
        if(c == true){
            return true;
        }
    }
    return false;
}

std::map<std::vector<int>, std::vector<int>>mp = std::map<std::vector<int>, std::vector<int>>();
std::vector<int>min = std::vector<int>();

void sort(std::vector<int>a, std::vector<int>ab){
    for(int i = 0; i < a.size(); i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < ab.size(); i++){
        std::cout << ab[i] << " ";
    }
    std::cout << std::endl;

    mp[a] = ab;
    if(sorted(a)){
        if(ab.size() < min.size()){
            min = ab;
        }
        else if(min.size() == 0){
            min = ab;
        }
        return;
    }

    for(int i = 0; i < a.size() - 1; i++){
        if(abs(a[i] - a[i + 1]) >= 2){
            std::vector<int>b = a;
            int temp = b[i];
            b[i] = b[i + 1];
            b[i + 1] = temp;
            std::vector<int>ab2 = ab;
            ab2[0]++;
            ab2.push_back(a[i + 1]);
            ab2.push_back(a[i]);
            if(mp[b].size() == 0){
                sort(b, ab2);
            }
            else if(mp[b][0] > ab2[0]){
                sort(b, ab2);
            }
        }
    }
    if(abs(a[0] - a[a.size() - 1]) >= 2){
        std::vector<int>b = a;
        int temp = b[0];
        b[0] = b[a.size() - 1];
        b[a.size() - 1] = b[0];
        std::vector<int>ab2 = ab;
        ab2[0]++;
        ab2.push_back(a[0]);
        ab2.push_back(a[a.size() - 1]);
        if(mp[b].size() == 0){
            sort(b, ab2);
        }
        else if(mp[b][0] > ab2[0]){
            sort(b, ab2);
        }
    }
}

int main(){
    int n = 0;
    std::cin >> n;
    std::vector<int>a = std::vector<int>();
    for(int  i = 0; i < n; i++){
        int b;
        std::cin >> b;
        a.push_back(b);
    }
    mp[a] = {0};
    sort(a, {0});
    for(int i = 1; i < min.size(); i++){
        std::cout << min[i] << " ";
        if(i % 2 == 0){
            std::cout << std::endl;
        }
    }
    std::cout << 0 << std::endl;
    return 0;
}