#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
int n1;
int ans=0;

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
unordered_map<int,unordered_map<int,int>> dp;
int go(int start, int end){
    if(dp[start][end])return dp[start][end];
    if(start>end){
         return 0;
    }
    if(start==end){
         return v[start];
    }
    int q1=v[start]+max(go(start+2,end),go(start+1,end-1));
    int q2=v[end]+max(go(start,end-2),go(start+1,end-1));
    return dp[start][end]= max(q1,q2);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      int n;
      //cin >> n;
      cin >>n1;
      v.resize(n1,0);
      for(int q=0;q<n1;q++){
        cin >> v[q];
      }
      
      cout << go(0,n1-1)<<endl;
      



    }
    return 0;
}   
