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
unordered_map<int,int> val;
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
int dfs(int src,int par,int dist=0){
    int k=INT_MAX;
    for(auto x: adjList[src]){
        if(x.first!=par){
            if(val[src])k=0;
                k=min(k,dfs(x.first,src,dist+1));
        }
    }
    return visited[src]=k;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        adjList.clear();
        visited.clear();
        cin >>nodes>>qry;edges=nodes-1;
        val[1]=1;
        for(int i=0;i<edges;i++){
                cin >> startPoint >> endPoint;
                adjList[startPoint].push_back(make_pair(endPoint,k));
                adjList[endPoint].push_back(make_pair(startPoint,k));
        } 
        dfs(1,-1);

        for(auto x:visited){
            cout << x.first <<":"<<x.second<<endl;
        }
        cout <<endl;

        int l,r,index,cse=1;
        while(qry--){
           cin >> cse;
           switch(cse){
           case 0:
            cin >>l;

           break;
           case 1:
            cin >> l;


             
           break;
            }
        }
    }
    return 0;
}