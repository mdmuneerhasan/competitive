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
/*



*/
vector<int> vec;
unordered_map<int,unordered_map<int,int>>dp;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
int solve(int keys,int copied,int cnt){
    if(keys==0)return cnt;
    if(keys>1)
    if(dp[keys][cnt])return dp[keys][cnt];
    int a=0,b=0,c=0;
    a=solve(keys-1,copied,cnt+1);
    b=solve(keys-1,copied,cnt+copied);
    if(keys>=3){
    c=solve(keys-3,cnt,2*cnt);    
    }
    return dp[keys][cnt]=max(a,max(b,c));
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      cin >> n;
      cout << solve(n,0,0);
      
    }
    return 0;
}