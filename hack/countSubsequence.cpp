#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define MOD 1000000007
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
    cin >>t;    while (t--)
    {
        string s;
        cin >> s;
        n=s.size();
        int index[26];
        for(int i=0;i<26;i++){
            index[i]=-1;
        }
        unordered_map<int,int>dp;
        dp[0]=1;
        for(int i=0;i<s.size();i++){
            int last=index[s[i]-'A'];
            if(last==-1){
                dp[i+1]=2*dp[i];
            }else{
                dp[i+1]=(2*dp[i]-dp[last-1]%MOD+MOD)%MOD;    
            }
            dp[i]%=MOD;
            index[s[i]-'A']=i;
        }
        cout << dp[n]<<endl;
        
      
    }
    return 0;
}