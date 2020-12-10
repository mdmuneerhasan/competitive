/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 12:16:21 Tuesday 14-April:2020*/
#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define sf(v)           sort(v.begin(),v.end())
#define ff              first
#define ss              second
#define mp              make_pair
#define pii             pair<int, int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int, vi, greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args) {    const char* comma = strchr(names + 1, ',');    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
vector<int> vec1,vec2,vec3,primes;
int dp[5001][5001];
int n,n1,n2,startPoint,k=0,x=0,y=0,z=0,endPoint,ans=0,cnt=0,q=0,qry=0;
int solve(int i,int j){
  if(i==n1)return 0;
  if(j==n2)return inf;
  if(dp[i][j])return dp[i][j];
  return dp[i][j]=min(solve(i+1,j+1)+abs(vec1[i]-vec2[j]),solve(i,j+1));  
}
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    cin >>n1>>n2;
    vec1.clear();
    vec1.resize(n1,0);
    for(int q=0;q<n1;q++){
      cin >> vec1[q];
    }

    vec2.clear();
    vec2.resize(n2,0);
    for(int q=0;q<n2;q++){
      cin >> vec2[q];
    }
    sf(vec1);
    sf(vec2);
    memset(dp,0,sizeof(dp));
    ans=solve(0,0);

    
    cout << ans<<endl;
    
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >>t;    
    while (t--)Muneer();
    return 0;
}