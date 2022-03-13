/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 23:01:15 Wednesday 05-August:2020*/
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
#define INF             INT_MAX
#define PS(x,y)         fixed<<setprecision(y)<<x
#define MOD             1000000007
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args) {    const char* comma = strchr(names + 1, ',');    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
vector<int> vec1,vec2,vec3,primes;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
int nodes,edges;
unordered_map<int,int> visited;
unordered_map<int,vector<pair<int,int>>> adjList;
void show(){
    for(auto i=0;i<=100;i++){
        auto x=adjList[i];
        cout<< i << "->";
        for(auto y:x){
            cout <<"("<< y.first <<","<<y.second<<")";
        }
        cout <<endl;
    }
}
int dfs(int src){
    if(src>100)return 0;
    int k=INF;
    for(auto x: adjList[src]){
            if(visited[x.first]>visited[src]+1){
                visited[x.first]=visited[src]+1;
                dfs(x.first);
            }
    }
    return k;
}

void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    
    adjList.clear();
    visited.clear();
    cin >>nodes;edges=nodes;
    for(int i=0;i<edges;i++){
            cin >> stt >> ent;
            adjList[stt].push_back(make_pair(ent,k));
    } 
    cin >>nodes;edges=nodes;
    for(int i=0;i<edges;i++){
            cin >> stt >> ent;
            adjList[stt].push_back(make_pair(ent,k));
    } 

    for(int i=0;i<=100;i++){
        visited[i]=INF;
        for(int j=1;j<=6;j++){
            if(adjList[i+j].size()==0){
               adjList[i].push_back({i+j,0});
            }else{
               adjList[i].push_back(adjList[i+j][0]);
            }
        }
    }

    // show();
    visited[1]=0;
    dfs(1);    
    
    cout << ((visited[100]==INF)?-1:visited[100])<<endl;
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    cin >>t;    
    while (t--)Muneer();
    return 0;
}