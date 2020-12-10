#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<int> vec;
int n,x,y,z,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
unordered_map<int,int> dp;
int solve(int cnt){
    if(dp[cnt]) return dp[cnt];
    if(cnt==n)return 0;
    int a=INT_MAX,b=INT_MAX,c=INT_MAX;
    if(n>=2*cnt){
        a=solve(2*cnt)+x;
    }
    if(n>=cnt+1){
        b=solve(cnt+1)+y;
    }
    if(2*(cnt-1)>cnt&&n>=2*(cnt-1)){
        c=solve(2*(cnt-1))+x+z;
    }
    return dp[cnt]=min(c,min(a,b));
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      cin >> n >> x >> y >> z ;
      cout << solve(1)<<endl; 

      
    }
    return 0;
}