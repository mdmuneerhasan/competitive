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
unordered_map<int,int>dp;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
int solve(int lenght){
    if(lenght==0)return 0;
    if(dp[lenght])return dp[lenght];
    ans=0;
    for(int i=1;i<=n1;i++){
        if(lenght>=i){
            ans=max(ans,solve(lenght-i)+vec[i-1]);
        }
    }
    
    return dp[lenght]=ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >>n1;
        vec.clear();
        vec.resize(n1,0);
        for(int q=0;q<n1;q++){
          cin >> vec[q];
        }
        cout << solve(n1)<<endl;
      
    }
    return 0;
}