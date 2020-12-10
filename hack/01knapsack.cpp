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

vector<pair<int,int>> vec;
int wt,n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
unordered_map<int,int> dp[10000];
int solve(int index,int wt){
    if(index==n){
        return 0;
    }
    if(dp[wt][index])return dp[wt][index];
    int a=0,b=0;
    a=solve(index+1,wt);
    if(wt>=vec[index].first){
        b=solve(index+1,wt-vec[index].first)+vec[index].second;
    }
    return dp[wt][index]= max(a,b);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      cin >> n>>wt;
      for(int i=0;i<n;i++){
          cin >>startPoint ;
          vec.push_back(make_pair(startPoint,0));
      }
      for(int i=0;i<n;i++){
          cin >>vec[i].second;
      }
      cout << solve(0,wt)<<endl;


      
    }
    return 0;
}