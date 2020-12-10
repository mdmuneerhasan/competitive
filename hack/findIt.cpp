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
    unordered_map<int,int> dp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >>k;
       for (int i=1; i<=sqrt(k); i++) 
    { 
        if (k%i == 0) 
        { 
            if (k/i == i) 
                {
                    dp[k/i]++;
                }
            else{
                dp[k/i]++;
                dp[i]++;
            }
        } 
    } 
    }
    // for(auto x:dp){
    //     cout << x.first <<":"<<x.second<<endl;
    // }
    // cout <<endl;

    cin >>t;    while (t--)
    {
      cin >> n;
      cout << dp[n]<<endl;
      
    }
    return 0;
}