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
string s1,s2;
unordered_map<int,unordered_map<int,int>>dp;
int solve(int i1,int i2){
    if(dp[i1][i2])return dp[i1][i2];
    if(i1==n1)return n2-i2; 
    if(i2==n2)return n1-i1; 
    if(s1[i1]==s2[i2])return solve(i1+1,i2+1);
    return dp[i1][i2]=min(solve(i1+1,i2),
                      min(solve(i1,i2+1),solve(i1+1,i2+1)))+1;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >> s1 >> s2;
        n1=s1.size();
        n2=s2.size();
        cout << solve(0,0)<<endl;

        
    }
    return 0;
}