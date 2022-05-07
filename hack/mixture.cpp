/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 17:37:41 Saturday 30-April:2022*/
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
int row,col;vector<vector<int > > vec;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
string s, s1 ,s2;
int dp[102][102];
int solve(int start,int end){

    if(start==end)return 0;
    if(dp[start][end]!=-1)
    return dp[start][end];

    int ans = INT_MAX;

    for(int i=start+1;i<=end;i++){
        int sum1=(vec2[i]-vec2[start])%100;
        int sum2 = (vec2[end+1]-vec2[i])%100;
        ans = min(ans,solve(start,i-1)+solve(i,end)+sum1*sum2);
    }

    return dp[start][end] = ans;

}
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    

    cin >>n1;
    vec1.clear();
    vec1.resize(n1,0);
    vec2.clear();
    vec2.resize(n1+1,0);

    for(int i=0;i<102;i++){
        for(int j=0;j<102;j++){
            dp[i][j]=-1;
        }
    }


    for(int q=0;q<n1;q++){
      cin >> vec1[q];
      vec2[q+1] = vec1[q]+vec2[q];

    }



    cout << solve(0,n1-1)<<endl;
    
    
    
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >>t;    
    while (t--)Muneer();
    return 0;
}