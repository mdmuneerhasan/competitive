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
string s;
unordered_map<int,int>dp;
int solve(int n){
    if(n==s.size()){
        return 1;
    }
    if(s[n]=='0')return 0;
    if(dp[n])return dp[n];
    int a=0,b=0,c=0;
    if(s.size()==n+1){
        a=dp[n]=solve(n+1);
    }else{
        int num=stoi(s.substr(n,2));
        if(num<=26){
            b= dp[n]=solve(n+2)+solve(n+1);
        }else{
            c=dp[n]= solve(n+1);
        }
    }
    return dp[n]=max(a,max(b,c));
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
      cin >> s;
      dp.clear();
      cout << solve(0)<<endl;

      
    }
    return 0;
}