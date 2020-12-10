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
unordered_map<int,unordered_map<int,int>>dp;
int solve(int index,int left){
    if(dp[index][left])return dp[index][left];
    if(left==0)return 1;
    if(index==n1)return 0;
    if(left>=vec[index]){
        return dp[index][left]=solve(index,left-vec[index])+solve(index+1,left);
    }
        return dp[index][left]=solve(index+1,left);

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    // cin >>t;    while (t--)
    {
        cin >>k>>n1;
        vec.clear();
        dp.clear();
        vec.resize(n1,0);
        for(int q=0;q<n1;q++){
          cin >> vec[q];
        }
        cout << solve(0,k)<<endl;
      
      
    }
    return 0;
}