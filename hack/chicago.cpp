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
unordered_map<int,double> pr;
unordered_map<int,list<pair<int,double>>> adjList;
void show(){
    for(auto x:adjList){
        cout<< x.first << "->";
        for(auto y:x.second){
            cout <<"("<< y.first <<","<<y.second<<")";
        }
        cout <<endl;
    }
}
void dfs(int src,int par){
    for(auto x: adjList[src]){
        if(pr[x.first]<(x.second)*pr[src]){   
            pr[x.first]=x.second*pr[src];
               dfs(x.first,src);
        }
    }
    for(auto x: adjList[src]){
        if(visited[x.first]==0){
                visited[src]=1;
           dfs(x.first,src);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        double k;
        adjList.clear();
        visited.clear();
        pr.clear();
        cin >>nodes>>edges;
        if(nodes==0)return 0;
        for(int i=0;i<edges;i++){
                cin >> startPoint >> endPoint>>k;
                adjList[startPoint].push_back(make_pair(endPoint,k/100.0));
                adjList[endPoint].push_back(make_pair(startPoint,k/100.0));
        } 

        pr[1]=1.0;
        
        dfs(1,-1);
        printf("%0.6f percent",pr[nodes]*100);
      
    }
    return 0;
}