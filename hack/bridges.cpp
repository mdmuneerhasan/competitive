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
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
unordered_map<int,unordered_map<int,int>>dp;
int solve(int index,int start){
    if(index==n1)return 0;
    int a=0,b=0;
    if(dp[index][start])return dp[index][start];
    if(vec[index].second>=start){
        b=solve(index+1,vec[index].second)+1;
    }
    a=solve(index+1,start);
    return dp[index][start]=max(a,b);
}
bool cmp(pair<int,int>x,pair<int,int>y){
    return x.first<=y.first;

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        cin >>n1;
        dp.clear();
        vec.clear();
        vec.resize(n1);
        for(int q=0;q<n1;q++){
          cin >> vec[q].first;
        }
        for(int q=0;q<n1;q++){
          cin >> vec[q].second;
        }
        sort(vec.begin(),vec.end(),cmp);
        cout << solve(0,0)<<endl;


         
    }
    return 0;
}