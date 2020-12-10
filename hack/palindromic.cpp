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
string s;
unordered_map<int,unordered_map<int,int>>dp;
bool isPalin(int start,int end){
    if(dp[start][end])return dp[start][end]==2;
    if(start==end){dp[start][end]=2;return true;}
    if(s[start]!=s[end]){dp[start][end]=1;return false;}
    if(start<end+1){
        dp[start][end]= isPalin(start+1,end-1)+1;
        return dp[start][end]-1;
    }
    dp[start][end]=2;
    return true;

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      cin >> n;
      cin >> s;
      cin >> qry;
      int l,r,val,index,cse=1;
      while(qry--){
         cin >> l>>r;
         if(isPalin(l-1,r-1)){
             cout << "YES"<<endl;
         }else{
             cout << "NO"<<endl;
         }

      }
      
    }
    return 0;
}