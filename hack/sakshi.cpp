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
unordered_map<string,int> visited;
unordered_map<string,list<string>> adjList;
unordered_map<string,list<string>> converted;

int dfs(string src){
    if(visited[src])return 0;
    visited[src]=1;
    int ans=adjList[src].size()%2;
    for(auto x: adjList[src]){
            if(visited[x]==0){
               ans+= dfs(x);
               
        }
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        adjList.clear();
        visited.clear();
        cin >>nodes;edges=nodes;
        string startPoint,endPoint,n1,n2;
        for(int i=0;i<edges;i++){
                cin >> startPoint >> endPoint>>n1>>n2;
                adjList[(startPoint+"-"+endPoint)].push_back( (n1+"-"+n2));
                adjList[ (n1+"-"+n2)].push_back( (startPoint+"-"+endPoint));
        } 
        ans=0;cnt=0;
        for(auto x :adjList){
            if(visited[x.first]==0){
                cnt+=dfs(x.first);
            ans++;
            }
        }
        cout << max(ans-1,(cnt-2)/2)<<endl;
      
    }
    return 0;
}