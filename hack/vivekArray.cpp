#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
const int MAX=17002;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<int> vec;
unordered_map<int,int> sum;
unordered_map<int,int> dp[MAX];
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
int solve(int start,int end){
    if(dp[start][end])return dp[start][end];
    if(start==end){
        return 0;
    }
    int n=end-start+1;
    int a=0,b=0,c=0;
    ans=0;
    for(int i=start+1;i<=end;i++){
        if(sum[i]-sum[start]==sum[end+1]-sum[i]){
        ans=max(solve(start,i-1),solve(i,end))+1;
        break;
        }
    }
    return dp[start][end]=ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        cin >>n1;
        vec.clear();
        vec.resize(n1,0);
        sum.clear();
        for(int i=0;i<MAX;i++){
            dp[i].clear();
        }

        for(int q=0;q<n1;q++){
          cin >> vec[q];
          sum[q+1]=vec[q]+sum[q];
        }
        cout << solve(0,n1-1)<<endl;
        
      
    }
    return 0;
}