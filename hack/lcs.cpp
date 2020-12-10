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
int n3,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
string s1,s2,s3;
unordered_map<int,unordered_map<int,unordered_map<int,int>>>dp;
int solve(int i1,int i2,int i3){
    for(int i=0;i<=n1;i++){
        dp[i][0][0]=0;
    }for(int i=0;i<=n2;i++){
        dp[0][i][0]=0;
    }for(int i=0;i<=n3;i++){
        dp[0][0][i]=0;
    }
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            for(int k=1;k<=n3;k++){
                if(s1[i-1]==s2[j-1]&&s1[i-1]==s3[k-1]){
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                }else{
                    dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                }
            }
        }
    }
    return dp[n1][n2][n3];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >> s1 >> s2 >> s3;
        n1=s1.size();
        n2=s2.size();
        n3=s3.size();
        cout << solve(0,0,0)<<endl;
      
    }
    return 0;
}