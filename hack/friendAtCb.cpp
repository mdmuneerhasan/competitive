/*
* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 14:50:26 Thursday 02-April:2020
*/
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
int mod,n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;
int dp[51][100000];
int solve(int lastNumber,int mark){
    if(lastNumber>0)
    if(dp[lastNumber][mark])return dp[lastNumber][mark]-1;
    if(__builtin_popcount(mark)==n)return 0;
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if((1<<i)&mark)continue;
        if(lastNumber==-1){
            ans=min(ans,solve(i,mark|(1<<i)));
        }else{
            ans=min(ans,solve(i,mark|(1<<i)) 
                +(vec[lastNumber]%mod*vec[i]%mod)%mod );

        }
    }
        if(lastNumber>0)
    dp[lastNumber][mark]=ans+1;
    return ans;
}
void setPrime(){
    vec.push_back(1);
    int mark[100000];
    memset(mark,1,sizeof(mark));
    for(int i=2;i*i<=100000;i++){
        if(mark[i]){
            vec.push_back(i);
            for(int j=i*i;j<100000;j+=i){
                mark[j]=0;
            }
        }
    }
    
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    setPrime();
    //signature(true);
    cin >>t;    while (t--)
    {     
          memset(dp,0,sizeof(dp));
          cin >> n1 >> mod;
          n=0;
          while (vec[n]<n1)n++;
          
          
          if(vec[n]!=n1){n--;}
          n++;
          cout << solve(-1,0)<<endl;
          
    }
    return 0;
}