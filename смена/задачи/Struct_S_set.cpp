#include <iostream>
#include <set>

int main(){
    std::set<int>st;

    int n;
    std::cin >> n;
    char d, lastD;
    int num, y = 0;

    for(int i = 0; i < n; i++){
        std::cin >> d >> num;
        if(d == '+' && (i == 0 || lastD == '+')){
            st.insert(num);
        }
        else if(d == '+' && lastD == '?'){
            st.insert((num + y) % 1000000000);
        }
        else if(d == '?'){
            y = *st.lower_bound(num);
            std::cout << y << std::endl;
        }
        lastD = d;
    }
}