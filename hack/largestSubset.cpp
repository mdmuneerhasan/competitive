/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 23:24:27 Saturday 16-May:2020*/
#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define SF(v)           sort(v.begin(),v.end())
#define F               first
#define S               second
#define UP(x)           for(int i=0;i<x.size();i++){if(x[i]<='z' && x[i]>='a')x[i]=char(x[i]-'a'+'A');}
#define LO(x)           for(int i=0;i<x.size();i++){if(x[i]<='Z' && x[i]>='A')x[i]=char(x[i]-'A'+'a');}
#define MP              make_pair
#define PII             pair<int, int>
#define MAXHEAP         priority_queue<int>
#define MINHEAP         priority_queue<int, vector<int>, greater<int> >
#define SETBIT(x)       __builtin_popcountll(x)
#define ZEROBIT(x)      __builtin_ctzll(x)
#define INF             1e18
#define PS(x,y)         fixed<<setprecision(y)<<x
#define MOD             1000000007
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args) {    const char* comma = strchr(names + 1, ',');    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
vector<int> vec1,vec2,vec3,primes;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
int dp[50][50];
int solve(int i,int mask){
    if(i>=n1)return 0;
    if(dp[i][mask]!=-1)return dp[i][mask];

    int a=solve(i+1,mask),b=0,c=vec1[i];
    int newMask=mask;
    for(int i=0;primes[i]<=50;i++){
        if(c%primes[i]==0){
            if((mask)&(1<<i)){
                dp[i][mask]=max(a,b);
                return dp[i][mask];
            }else{
                newMask|=1<<i;
            }
        }
    }

    b=solve(i+1,newMask)+1;
    dp[i][mask]=max(a,b);
    return dp[i][mask];
}
void Muneer(){
    memset(dp,-1,sizeof(dp));
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    cin >>n1;
    vec1.clear();
    vec1.resize(n1,0);
    for(int q=0;q<n1;q++){
      cin >> vec1[q];
    }
    ans=solve(0,0);
    cout << ans<<endl;
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >>t;    
    bool seive[100001]={0};
        for(int i=2;i<100;i++){
        if(seive[i]==0){
            primes.push_back(i);
            for(int j=i*i;j<100001;j+=i){
                seive[j]=1;
            }
        }
    }
    
    while (t--)Muneer();
    return 0;
}