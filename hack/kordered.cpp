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
vector<int> vec2;
unordered_map<int,unordered_map<int,int>>dp;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
int solve(int i1,int i2){
    if(i1==n1||i2==n2)return 0;
    if(dp[i1][i2])return dp[i1][i2]-1;
    if(vec[i1]==vec2[i2]){
        int a= solve(i1+1,i2+1)+1;
        // db(i1,i2,a);
        return a;
    }
    dp[i1][i2]= max(solve(i1+1,i2),solve(i1,i2+1))+1;
    return dp[i1][i2]-1;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      cin >> n1 >> n2 >>k ;
      vec.clear();
      vec.resize(n1);
      for(int q=0;q<n1;q++){
        cin >> vec[q];
      }
      
      vec2.clear();
      vec2.resize(n2);
      for(int q=0;q<n2;q++){
        cin >> vec2[q];
      }

      cout << solve(0,0)+k<<endl;

      
    }
    return 0;
}