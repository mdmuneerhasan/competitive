/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 01:39:47 Wednesday 14-April:2021*/
#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define SF(v)           sort(v.begin(),v.end())
#define UP(x)           for(int i=0;i<x.size();i++){if(x[i]<='z' && x[i]>='a')x[i]=char(x[i]-'a'+'A');}
#define LO(x)           for(int i=0;i<x.size();i++){if(x[i]<='Z' && x[i]>='A')x[i]=char(x[i]-'A'+'a');}
#define MAXHEAP         priority_queue<int>
#define MINHEAP         priority_queue<int, vector<int>, greater<int> >
#define SETBIT(x)       __builtin_popcountll(x)
#define ZEROBIT(x)      __builtin_ctzll(x)
#define PS(x,y)         fixed<<setprecision(y)<<x
#define MOD             1000000007
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args) {    const char* comma = strchr(names + 1, ',');    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
vector<int> vec1,vec2,vec3,primes;
int row,col;vector<vector<int > > vec;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
string s, s1 ,s2;
int dp[1000][1000];
int solve(int in,int rem){
    if(in==n1){
        return 0;
    }
    if(dp[in][rem]!=-1)
    return dp[in][rem];

    if(rem>=vec1[in]){
        return dp[in][rem]=max(solve(in+1,rem-vec1[in])+vec2[in],
            solve(in+1,rem));
    }
    return dp[in][rem]=solve(in+1,rem);

}
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,a=0,b=0;
    

    cin >>n1>>k;
    vec1.clear();
    vec1.resize(n1,0);
    n2=n1;
    vec2.clear();
    vec2.resize(n2,0);
    for(int q=0;q<n1;q++){
      cin >> vec1[q];
      vec2[q]=q+1;

    }
    

    memset(dp,-1,sizeof(dp));

    cout << solve(0,k)<<endl;
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >>t;    
    while (t--)Muneer();
    return 0;
}