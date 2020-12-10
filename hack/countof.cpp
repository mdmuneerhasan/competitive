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
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
unordered_map<int,unordered_map<int,unordered_map<int,int>>>dp;

int solve(int n,int b,int c){
    if(b<0||c<0)return 0;
    if((b==0&&c==0)||n==0)return 1;
    if(dp[n][b][c])return dp[n][b][c]-1;
    dp[n][b][c]=solve(n-1,b,c)+solve(n-1,b-1,c)+solve(n-1,b,c-1)+1;
    return dp[n][b][c]-1;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        dp.clear();
      cin >> n;
      cout << solve(n,1,2)<<endl;
      
    }
    return 0;
}