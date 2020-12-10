#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<int> vec;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
unordered_map<int,list<int>> adjList;
void show(){
    for(auto x:adjList){
        cout<< x.first << "->";
        for(auto y:x.second){
            cout << y <<",";
        }
        cout <<endl;
    }
}
unordered_map<int,int> visited;
void dfs(int src){
    visited[src]=1;
    cout << src << ", ";
        for(auto x:adjList[src]){
            if(!visited[x])
            dfs(x);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >> n;
        for(int i=0;i<n;i++){
           cin >> startPoint >> endPoint;
           adjList[startPoint].push_back(endPoint);
           adjList[endPoint].push_back(startPoint);
        } 
        for(auto x:adjList){
            if(visited[x.first]==0){
                dfs(x.first);ans++;
                cout <<endl;
            }
        }
      cout << ans<<endl;
    }
    return 0;
}