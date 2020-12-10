/*
* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 09:53:22 Friday 10-April:2020
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
void signature(bool enable){
    if(!enable)return;
    cout << "Friday 10-April:2020"<<endl;
    cout << "Name : Muneer Hasan"<<endl;
    cout << "Roll No.: 17BCS054"<<endl;
}
vector<int> vec,primes;
int n,n1,n2,startPoint,k=0,x=0,y=0,z=0,endPoint,ans=0,cnt=0,q=0,qry=0;
int dp[1001][1001][2];
int mod=1000000007;
int solve(int boys,int girl,bool isBoy=false){
    if(girl==0 &&boys==0 )return 1;
    if(dp[boys][girl][isBoy])return dp[boys][girl][isBoy];
    int a=0,b=0;
    if(!isBoy){
    for(int i=1;i<=n1;i++){
        if(boys-i>=0)
        a+=solve(boys-i,girl,true);
    }
    }else{
    for(int i=1;i<=n2;i++){
        if(girl-i>=0)
        a+=solve(boys,girl-i,false);
    }    
    }
    
    return dp[boys][girl][isBoy]=(a+b)%mod;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //signature(true);
    //cin >>t;    while (t--)
    {   cin >> x >> y >> n1 >>n2;


    ans=solve(x,y,0)+solve(x,y,1);
    cout << ans<<endl;
          
          
          
    }
    return 0;
}