/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 13:24:28 Saturday 26-September:2020*/
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

struct Node
{
  int x1,y1,x2,y2,t;
};

vector<Node> vec1,vec2,vec3,primes;
unordered_map<int,int> dp;
int x1,x2,y1,y2,n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
unordered_map<string,pair<string,int>> pipes;
int solve(int x1,int y1){

}
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    cin >>n1;
    cin >>x1>>y1>>x2>>y2; 
    vec1.clear();
    vec1.resize(n1);
    for(int q=0;q<n1;q++){
      cin >>x;
      cin >>y;
      cin >>a;
      cin >>b;
      cin >>c;
      vec1[q].x1=x;
      vec1[q].y1=y;
      vec1[q].x2=a;
      vec1[q].y2=b;
      vec1[q].t=c;
      pipes[x+"-"+y]={a+"-"+b,c};
      pipes[a+"-"+b]={x+"-"+y,c};
    }
    cout << solve(x1,y1)<<endl;
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    cin >>t;    
    while (t--)Muneer();
    return 0;
}