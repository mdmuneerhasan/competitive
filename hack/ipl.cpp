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
unordered_map<int,int>dp[2][2];
int solve(int index=0,bool l1=0,bool l2=0){
    if(index==n1)return 0;
    if(dp[l1][l2][index])return dp[l1][l2][index];
    if(l1&&l2){
        return dp[l1][l2][index]=solve(index+1,l2,0);
    }else{
        return dp[l1][l2][index]=max(solve(index+1,l2,1)+vec[index],solve(index+1,l2,0));
    }
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
        cout << solve()<<endl;
      
    }
    return 0;
}