#include <iostream>
#include <vector>
#include <string>
#include <cmath>

bool isPalindrome(std::string str){
    int l = 0;
    int r = str.size()-1;
    while(l < r){
        if(str[l] != str[r])return false;
        l++;
        r--;
    }
    return true;
}

bool f(std::string a, std::string b){
    if(a.size() >= b.size())return false;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i])return false;
    }
    return true;
}

bool s(std::string a, std::string b){
    int i = 0;
    while(i < std::min(a.size(), b.size())){
        if(a[i] != b[i]){
            break;
        }
        i++;
    }
    if(a[i] < b[i])
        return true;
    return false;
}

int main(){
    std::vector<std::string>v = std::vector<std::string>();
    std::string str;
    std::string ans;
    std::cin >> str;
    for(int l = 2; l <= str.size(); l++){
        for(int x = 0; x < str.size() - l + 1; x++){
            std::string s = str.substr(x, l);
            if(isPalindrome(s)){
                v.push_back(s);
                std::cout << s << std::endl;
            }
        }
    }
    std::cout << "--------" << std::endl;
    if(v.size() == 0){
        std::cout << -1 << std::endl;
        return 0;
    }
    if(v.size() == 1){
        ans = v[0];
    }
    else{
        ans = v[0];
        for(int i = 1; i < v.size(); i++){
            std::cout << ans << " " << v[i] << " " << f(ans, v[i]) << " " << s(v[i], ans) << std::endl;
            if(f(v[i], ans) || s(v[i], ans))
                ans = v[i];
        }
    }
    std::cout << ans << std::endl;

    return 0;
}