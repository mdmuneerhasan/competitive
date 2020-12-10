#include<bits/stdc++.h>
using namespace std;
#define int long long int
stringstream vin,vout;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<int> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        string s;
        cin >> s;
        int len=s.size();
        int dp[len];
        int dp2[len];
        dp[0]=1;dp2[len-1]=1;
        n1=1;n2=1;
        for(int i=1;i<len;i++){
            if(s[i]==s[i-1]){
                dp[i]=dp[i-1]^n1^(n1+1);
                n1++;
            }else{
                n1=1;
                dp[i]=dp[i-1]^1;
            }
            if(s[len-i]==s[len-i-1]){
                dp2[len-i-1]=dp2[len-i]^n2^(n2+1);
                n2++;
            }else{
                n2=1;
                dp2[len-i-1]=dp2[len-i]^1;
            }
        }
        
        
        
        
        if(dp[len-1]==0){
            cout << "YES"<<endl;
        }else{
            ans=0;
            for(int i=0;i<len-1;i++){
                    // cout << dp[i]<< " "<<dp2[i+1]<<endl;
                if((dp[i]^dp2[i+1])==0){
                    ans=1;
                    // break;
                }
            }
            if(ans){
                cout << "YES"<<endl;
            }else{
                cout << "NO"<<endl;
            }
        }
      
    }
    return 0;
}