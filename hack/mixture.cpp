#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> vec;
vector<vector<int>> dp;
int n1;
int sum(int end,int start){
  int ans=0;
  for(int i=start;i<=end;i++){
  ans+=vec[i];
  ans%100;
  }
  return ans;
}
int solve(int start,int end){
    if(start>=end)return 0;
    if(dp[start][end])return dp[start][end];
    dp[start][end]=INT_MAX;
    for(int i=start;i<end;i++){
        dp[start][end]=min(dp[start][end],
        solve(start,i)+solve(i+1,end)+
                      (sum(i,start)%100)
                        *(sum(end,i+1)%100)
        
        );
    }
    return dp[start][end];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >>n1;
        vec.resize(n1,0);
        dp.resize(n1+1,vector<int>(n1+1,0));
        
        for(int q=0;q<n1;q++){
          cin >> vec[q];
        }

        
        cout << solve(0,n1-1)<<endl;
        // (dp[i]-dp[j-1]+100)%100
        

        // cout << <<endl;
    }
    return 0;
}