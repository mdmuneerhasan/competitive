#include<bits/stdc++.h>
using namespace std;
#define int long long int
stringstream vin,vout;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<int> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;
unordered_map<int,unordered_map<int,int>>dp;
void solve(int i,int j,int c=1){
    if(i<0 || j<0 || i==n ||j==n)return;
    ans=max(ans,c);
    if(dp[i+1][j+2]){
        dp[i+1][j+2]=0;
        solve(i+1,j+2,c+1);
        dp[i+1][j+2]=1;
    }
    if(dp[i+1][j-2]){
        dp[i+1][j-2]=0;
        solve(i+1,j-2,c+1);
        dp[i+1][j-2]=1;
    }
    if(dp[i-1][j+2]){
        dp[i-1][j+2]=0;
        solve(i-1,j+2,c+1);
        dp[i-1][j+2]=1;
    }
    if(dp[i-1][j-2]){
        dp[i-1][j-2]=0;
        solve(i-1,j-2,c+1);
        dp[i-1][j-2]=1;
    }
    if(dp[i-2][j-1]){
        dp[i-2][j-1]=0;
        solve(i-2,j-1,c+1);
        dp[i-2][j-1]=1;
    }
    if(dp[i-2][j+1]){
        dp[i-2][j+1]=0;
        solve(i-2,j+1,c+1);
        dp[i-2][j+1]=1;
    }
    if(dp[i+2][j-1]){
        dp[i+2][j-1]=0;
        solve(i+2,j-1,c+1);
        dp[i+2][j-1]=1;
    }
    if(dp[i+2][j+1]){
        dp[i+2][j+1]=0;
        solve(i+2,j+1,c+1);
        dp[i+2][j+1]=1;
    }
    

     
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        ans=0;cnt=0;
      cin >> n;
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
          cin >> dp[i][j];
          cnt+=dp[i][j];
          }
      }
      dp[0][0]=0;
      solve(0,0);
      
      cout << cnt-ans<<endl;
      
      
    }
    return 0;
}