#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>

struct Node{
    std::map<int, int>to;
    bool term = false;
    Node(){}
};

int alphabet = 26;
std::vector<Node>trie = std::vector<Node>(1);

void insert(std::string S){
    int v = 0;
    for(auto c : S){
        if(!trie[v].to.count(c - 'a')){
            trie[v].to[c - 'a'] = trie.size();
            trie.push_back(Node());
        }
        v = trie[v].to[c - 'a'];
    }
    trie[v].term = true;
}

std::vector<int> TZ_FUNC(std::string s){
	int n = (int) s.length();
	std::vector<int> z (n);
	for (int i=1; i<n; ++i)
		while (i + z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
	return z;
}

std::vector<int> z_function (std::string s) {
	int n = (int) s.length();
	std::vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = std::min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

int test_max(int v){
    int max = 0;
    int term = 0;
    if(trie[v].term){
        term = 1;
    }
    for(int i = 0; i < alphabet; i++){
        if(trie[v].to[i] != 0){
            int m = test_max(trie[v].to[i]);
            max = std::max(m, max);
        }
    }

    term += max;
    
    return term;
}

int main(){
    std::vector<std::vector<char>>num_pad = {{' '},            {'a', 'b', 'c'}, {'d', 'e', 'f'},
                                             {'g', 'h', 'i'},  {'j', 'k', 'l'}, {'m', 'n', 'o'},
                                             {'p','a','r','s'},{'t', 'u', 'v'}, {'w','x','y','z'}};
    std::vector<std::string>dict = std::vector<std::string>();
    std::vector<std::string>pod_dict;
    int n, m;

    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::string str;
        std::cin >> str;
        dict.push_back(str);
    }

    std::cin >> m;

    pod_dict = dict;

    for(int i = 0; i < m; i++){
        int num;
        std::cin >> num;
        for(int j = 0; j < ){

        }
    }

    return 0;
}

/*
tests

5
po
pod
sasha
shla
shosse
12
7 4 5 7 2 7 6 1 7 4 6 1

2
sem
vosem
6
7 8 9 7 8 1

*/