#include<bits/stdc++.h>
using namespace std;
#define int long long int
stringstream vin,vout;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<int> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;
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
    int k=0;
    for(auto x: adjList[src]){
        if(x.first!=par){
            if(!visited[x.first]){
                k=max(k,dfs(x.first,src)+x.second);
            }
        }
    }
    return k;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        adjList.clear();
        visited.clear();
        cin >>nodes;edges=nodes-1;
        for(int i=0;i<edges;i++){
                cin >> startPoint >> endPoint;
                adjList[startPoint].push_back(make_pair(endPoint,k));
                adjList[endPoint].push_back(make_pair(startPoint,k));
        } 
        // show();
        ans=0;
        
        for(int i=1;i<=nodes;i++){
            int x=adjList[i].size();
            ans+=x*(x-1)/2;
        }
        cout << ans<<endl;
      
    }
    return 0;
}