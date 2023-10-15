#include <iostream>
#include <string>
#include <vector>
#include <map>

std::vector<std::string>strs = std::vector<std::string>();
std::vector<int>sum = std::vector<int>();

std::map<std::string, int>mp = std::map<std::string, int>();

int f(std::string str){
    //std::cout << str << std::endl;
    int m = mp[str];
    if(m > 0)return m;
    int max = 0;
    for(int i = 0; i < strs.size(); i++){
        int a = str.find(strs[i]);
        if(a != std::string::npos){
            std::string fstr = str;
            fstr.erase(a, strs[i].size());
            int b = f(fstr) + sum[i];
            if(b > max){
                max = b;
            }
        }
    }
    mp[str] = max;
    return max;
}

int main(){
    int n;
    std::cin >> n;
    std::map<char, int>st = std::map<char, int>();
    for(int i = 0; i < n; i++){
        char col;
        int s;
        std::cin >> col >> s;
        st[col] = s;
    }
    std::string str;
    std::cin >> str;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::string s;
        std::cin >> s;
        int a = 0;
        for(int j = 0; j < s.size(); j++){
            a += st[s[j]];
        }
        strs.push_back(s);
        sum.push_back(a);
    }
    std::cout << f(str) << std::endl;
    return 0;
}