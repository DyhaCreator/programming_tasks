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
 ll n, m, k, l; 
 cin>>n>>m>>k>>l; 
 cout<<(k-1)*m + l; 
 return 0; 
}