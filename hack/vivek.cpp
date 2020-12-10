/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 21:30:45 Monday 03-August:2020*/
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
int nodes,edges;
unordered_map<int,int> visited;
unordered_map<int,list<pair<int,int>>> adjList;
void show(){
    for(auto x:adjList){
        cout<< x.first << "->";
        for(auto y:x.second){
            cout <<"("<< y.first <<","<<y.second<<")";
        }
        cout <<endl;
    }
}
int dfs(int src,int par){
    visited[src]=1;
    int k=1;
    for(auto x: adjList[src]){
        if(x.first!=par){
            if(!visited[x.first]){
                k+=dfs(x.first,src);
            }
        }
    }
    return k;
}

void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    
    adjList.clear();
    visited.clear();
    cin >>nodes>>edges;
    for(int i=0;i<edges;i++){
            cin >> stt >> ent;
            adjList[stt].push_back(make_pair(ent,k));
            adjList[ent].push_back(make_pair(stt,k));
    } 
    // show();
    ans=INT_MAX;
    
    for(int i=1;i<=nodes;i++){
        if(!visited[i]){
        ans=min(ans,dfs(i,-1));
        }
    }
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