#include <iostream>
#include <vector>
#include <string>
#include <set>

int main(){
    std::set<unsigned long long>st;
    char d;
    while(true){
        std::string str;
        std::cin >> d;
        if(d == '#'){
            break;
        }
        std::cin >> str;
        unsigned long long ans = 0;
        for(int i = 0; i < str.size(); i++){
            ans = (ans * 27) + (str[i] - 'a' + 1);
        }
        if(d == '+'){
            st.insert(ans);
        }
        else if(d == '-'){
            st.erase(ans);
        }
        else if(d == '?'){
            if(st.find(ans) != st.end()){
                std::cout << "YES" << std::endl;
            }
            else{
                std::cout << "NO" << std::endl;
            }
        }
    }
    return 0;
}