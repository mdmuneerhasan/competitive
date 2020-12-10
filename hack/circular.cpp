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
unordered_map<int,int > preSum;
unordered_map<int,unordered_map<int,int>> dp;
int n,n1,n2,startPoint,k,enpreSumoint,ans=0,cnt=0,q=0,qry=0;
int solve(int start ,int end){
    if(dp[start][end]!=-1)return dp[start][end];
    if(start==end)return dp[start][end]=0;
    dp[start][end]=INT_MAX;
    int sum=preSum[end]-preSum[start-1];
    for(int i=start;i<end;i++){
        dp[start][end]=min(dp[start][end],solve(start,i)+solve(i+1,end)+sum);
    }
    return dp[start][end];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    // cin >>t;    while (t--)
    {
        cin >>n1;
        vec.clear();
        for(int i=0;i<2*n1;i++){
            for(int j=0;j<2*n1;j++){
            dp[i][j]=-1;
            }EI;YH N
        }
        vec.resize(2*n1,0);
        
        for(int q=0;q<n1;q++){
          cin >> vec[q];
          vec[q+n1]=vec[q];
        }
        preSum[0]=vec[0];
        ans=INT_MAX;
        for(int i=0;i<2*n1;i++){
            preSum[i]=preSum[i-1]+vec[i];
        }
        ans=INT_MAX;
        for(int i=0;i<n1;i++){
            ans=min(ans,solve(i,i+n1-1));
        }
        cout << ans<<endl;
        
      
    }
    return 0;
}