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
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
int nodes,edges;
unordered_map<int,int> visited;
unordered_map<int,unordered_map<int,unordered_map<int,int>>>dp;
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
    dp[src][par][vec[src]]++;
    dp[src][par][0]=1;
    int k=0;
    for(auto x: adjList[src]){
        if(x.first!=par){
            if(!dp[x.first][src][0]){
                k=max(k,dfs(x.first,src));

            }

        for(int i=1;i<=20;i++){
            dp[src][par][i]+=dp[x.first][src][i];
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
        cin >>n1>>nodes;
        vec.clear();
        vec.resize(n1+1,0);
        for(int q=0;q<n1;q++){
          cin >> vec[q+1];
        }

        adjList.clear();
        visited.clear();
        edges=nodes;
        for(int i=0;i<edges;i++){
                cin >> startPoint >> endPoint;
                adjList[startPoint].push_back(make_pair(endPoint,k));
        } 
        // show();
        ans=0;
        nodes++;
        for(int i=1;i<=nodes;i++){
                  visited.clear();
                  
               dfs(i,-1);
               db(i);

               for(auto x:dp[i][-1]){
                   cout << x.first <<":"<<x.second<<endl;
                   ans=max(ans,x.second);
               }
               cout <<endl;
        }
        cout << ans<<endl;


        
    }
    return 0;
}