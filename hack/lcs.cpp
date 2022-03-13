/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
<<<<<<< HEAD
* 17:57:17 Tuesday 13-April:2021*/
=======
* 07:27:32 Friday 04-September:2020*/
>>>>>>> competitive/master
#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define SF(v)           sort(v.begin(),v.end())
<<<<<<< HEAD
#define UP(x)           for(int i=0;i<x.size();i++){if(x[i]<='z' && x[i]>='a')x[i]=char(x[i]-'a'+'A');}
#define LO(x)           for(int i=0;i<x.size();i++){if(x[i]<='Z' && x[i]>='A')x[i]=char(x[i]-'A'+'a');}
=======
#define F               first
#define S               second
#define UP(x)           for(int i=0;i<x.size();i++){if(x[i]<='z' && x[i]>='a')x[i]=char(x[i]-'a'+'A');}
#define LO(x)           for(int i=0;i<x.size();i++){if(x[i]<='Z' && x[i]>='A')x[i]=char(x[i]-'A'+'a');}
#define MP              make_pair
#define PII             pair<int, int>
>>>>>>> competitive/master
#define MAXHEAP         priority_queue<int>
#define MINHEAP         priority_queue<int, vector<int>, greater<int> >
#define SETBIT(x)       __builtin_popcountll(x)
#define ZEROBIT(x)      __builtin_ctzll(x)
<<<<<<< HEAD
#define PS(x,y)         fixed<<setprecision(y)<<x
#define MOD             1000000007
#define LS1             cin >> s1;n1=s1.size()
#define LS2             cin >> s2;n2=s2.size()
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args) {    const char* comma = strchr(names + 1, ',');    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
vector<int> vec1,vec2,vec3,primes;
int row,col;vector<vector<int>> vec;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
string s, s1 ,s2;
string dp[1000][1000];
string solve(int i,int j){
    if(i==n1 || j==n2){
        return "";
    }
    if(!dp[i][j].empty())return dp[i][j];
    if(s1[i]==s2[j]){
        return s1[i]+solve(i+1,j+1);
    }
    string a=solve(i+1,j);
    string b=solve(i,j+1);
    if(a.length()>=b.length()){
        return dp[i][j]=a;
    }
    return dp[i][j]=b;
}
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,a=0,b=0;
    
    LS1;    LS2;

    cout << solve(0,0)<<endl;
=======
#define INF             1e18
#define PS(x,y)         fixed<<setprecision(y)<<x
#define MOD             1000000007
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args) {    const char* comma = strchr(names + 1, ',');    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
vector<int> vec1,vec2,vec3,primes;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;

void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    string s1,s2;
    cin >> s1 >> s2;

    n1=s1.size();
    n2=s2.size();

    unordered_map<int,unordered_map<int,pair<int,string>>> dp;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(s1[i]==s2[j]){
                dp[i][j].first=dp[i-1][j-1].first+1;
                dp[i][j].second=dp[i-1][j-1].second+s1[i];
                
            }else{
                if(dp[i-1][j].first>=dp[i][j-1].first){
                dp[i][j].first=dp[i-1][j].first;
                dp[i][j].second=dp[i-1][j].second;
                }else{
                dp[i][j].first=dp[i][j-1].first;
                dp[i][j].second=dp[i][j-1].second;

                }
            }
        }
    }

    cout << dp[n1-1][n2-1].second<<endl;    
>>>>>>> competitive/master
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >>t;    
    while (t--)Muneer();
    return 0;
}