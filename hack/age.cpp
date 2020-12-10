/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 23:59:52 Tuesday 14-April:2020*/
#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define sf(v)           sort(v.begin(),v.end())
#define ff              first
#define ss              second
#define mp              make_pair
#define pii             pair<int, int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int, vector<int>, greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args) {    const char* comma = strchr(names + 1, ',');    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
vector<pii> vec1,vec2,vec3,primes;
int n,n1,n2,startPoint,k=0,x=0,y=0,z=0,endPoint,ans=0,cnt=0,q=0,qry=0;
unordered_map<int,unordered_map<int,unordered_map<int,unordered_map<int,int>>>> dp;
int solve(int index,int a,int b,int c ){
    if(index==n1){
        // if(ans<300)
        // db(ans,pat);
        return 0;
    }
    // if(dp[index][a][b][c])return dp[index][a][b][c];
    int a1=inf,b1=inf,c1=inf;
    if(a+b+c<vec1[index].ff){
        a1=solve(index+1,a,b,c)+vec1[index].ss;
        b1=solve(index+1,a,b,c+vec1[index].ff)+2*vec1[index].ss;
    }else{
        a1=solve(index+1,a,b,c)+vec1[index].ss;
        b1=solve(index+1,a,b,c+vec1[index].ff)+2*vec1[index].ss;
        if(a>=vec1[index].ff){
        c1=solve(index+1,b,c,0);
        }else if(a+b>=vec1[index].ff){
            b=b+a-vec1[index].ff;
        c1=solve(index+1,b,c,0);
        }else{
            c=c+b+a-vec1[index].ff;
        c1=solve(index+1,0,c,0);
        }
    }

    return dp[index][a][b][c]=min(a1,min(b1,c1));
}
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    cin >>n1;
    vec1.clear();
    vec1.resize(n1);
    for(int q=0;q<n1;q++){
      cin >> vec1[q].first>> vec1[q].ss;
    }
    ans= solve(0,0,0,0);
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