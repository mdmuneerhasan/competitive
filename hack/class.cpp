/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 01:24:53 Thursday 15-April:2021*/
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
int row,col;vector<vector<int>> vec;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
string s, s1 ,s2;

void Muneer(){
    int ans=0,cnt=0,x=0,y=0,a=0,g,b=0;
    
    cin >> b >> g >> n1 >> n2;

    int dp[b+1][g+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=b;i++){
        dp[i][0]=1;
    }

    for(int j=0;j<=g;j++){
        dp[0][j]=1;
    }
    for(int i=1;i<b;i++){
        for(int j=1;j<g;j++){
            for(int k=1;k<=n1;k++){
                for(int l=1;l<=n2;l++){
                    if(i-k>=0 && j-l>=0){
                        dp[i][j]+=dp[i-k][j-l];
                        dp[i][j]=dp[i][j]%MOD;
                        
                    }
                }
            }
        }
    }



    cout << dp[b-1][g-1]<<endl;
    
    
}
int32_t main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >>t;    
    while (t--)Muneer();
    return 0;
}