#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
vector<int> dp;
int n1;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
bool possible=false;
int go(int total){
    if(total==0){
        possible =true;
        return 0;
    }
    // db(total);
   if(dp[total])return dp[total];
    int mi=INT_MAX;
    for(int i=0;i<n1;i++){
        if(total>=v[i])
        mi=min(mi,1+go(total-v[i]));
    } 
      
    return dp[total]=mi;

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
      int total,n;
      cin >> total;
      cin >>n1;
      v.resize(n1,0);
      dp.resize(n1,0);
      for(int q=0;q<n1;q++){
        cin >> v[q];
      }
      int ans= go(total);
      if(possible){
          cout << ans<<endl;
      }else{
          cout << -1<<endl;
      }

    }
    return 0;
}