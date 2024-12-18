#include<iostream> 
#include<vector> 
#include<stack> 
#include<queue> 
#include <climits> 
#include<algorithm> 
#include<deque> 
using namespace std; 
using ll = long long; 
using stll = stack<long long>; 
using vll = vector<long long>; 
using dll = deque<long long>; 
using qll = queue<long long>; 
const ll INF = LLONG_MAX; 
int main(){ 
 ios_base::sync_with_stdio(false); 
 cin.tie(0); 
 ll h, m; 
 char c; 
 cin>>h>>c>>m; 
 if((h==6 && m>=36) || (h==11 && m<=46)) cout<<"Morning";  
 else if((h==11 && m>=47) || (h==17 && m<=58)) cout<<"Day"; 
 else if((h==17 && m>=59) || (h==0 && m<=42)) cout<<"Evening"; 
 else if((h==0 && m>=43) || (h==6 && m<=35)) cout<<"Night"; 
 else if(h>6 && h<11) cout<<"Morning"; 
 else if(h>11 && h<17) cout<<"Day"; 
 else if(h>17 && h<=23) cout<<"Evening"; 
 else cout<<"Night"; 
}