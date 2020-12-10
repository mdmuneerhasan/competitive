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
vector<pair<int,pair<int,int>>> vec;
unordered_map<int,unordered_map<int,int>>dp;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
int solve(int index,int time){
    if(index==n1||time==k){
        return 0;
    }
    if(dp[index][time])return dp[index][time];
    int a=INT_MIN,b=INT_MIN;
    a=solve(index+1,time);
    if(vec[index].first>=time+vec[index].second.second){
        b=solve(index+1,time+vec[index].second.second)+vec[index].second.first;
    }
    return dp[index][time]=max(a,b);

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >>k>>n1;
        vec.clear();
        vec.resize(n1);
        for(int q=0;q<n1;q++){
          cin >> vec[q].second.first;
        }
        for(int q=0;q<n1;q++){
          cin >> vec[q].second.second;
        }
        for(int q=0;q<n1;q++){
          cin >> vec[q].first;
        }
        sort(vec.begin(),vec.end());
        cout << solve(0,0)<<endl;
      
    }
    return 0;
}