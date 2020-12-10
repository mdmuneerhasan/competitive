/*
* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 00:11:37 Tuesday 07-April:2020
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
    cout << "Tuesday 07-April:2020"<<endl;
    cout << "Name : Muneer Hasan"<<endl;
    cout << "Roll No.: 17BCS054"<<endl;
}
vector<int> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;
int arr[]={3,5,10};
int dp[1000001][3];
int solve(int n,int in=0){
    if(in==3){
    if(n==0)return 1;return 0;}
    if(dp[n][in]!=-1)return dp[n][in];
    if(n>=arr[in]){
        return dp[n][in]=solve(n-arr[in],in)+solve(n,in+1);
    }
    return dp[n][in]=solve(n,in+1);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //signature(true);
    //cin >>t;    while (t--)
    {   
          
          cin >> n;
          memset(dp,-1,sizeof(dp));
          ans=solve(n);
          cout << ans<<endl;
          
    }
    return 0;
}