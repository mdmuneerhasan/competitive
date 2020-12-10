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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        n=200003;
        cin >>n1;
        vec.clear();
        vec.resize(n,0);
        for(int q=0;q<n1;q++){
            cin >> k;
            vec[k]++;
        }
        unordered_map<int,int>dp;
        dp[0]=0;
        dp[1]=vec[1];
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-2]+vec[i]*i,dp[i-1]);
        }
        cout<<dp[n-1];
      
    }
    return 0;
}