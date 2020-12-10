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
int n,n1,n2,e,startPoint,M1,M2,N1,N2,k,endPoint,ans=0,cnt=0,q=0,qry=0;
unordered_map<int,list<int>> adjList;
unordered_map<int,int> distFromSource;
unordered_map<int,int> distFromDestination;
unordered_map<int,int> distFromSource2;
unordered_map<int,int> distFromDestination2;
void dfs(int src,int dist,unordered_map<int,int> & distMap){
        distMap[src]=dist;
    for(auto x:adjList[src]){
        if(distMap[x]==0)
        dfs(x,dist+1,distMap);
    }
}
void show(){
    for(auto x:adjList){
        cout<< x.first << "->";
        for(auto y:x.second){
            cout << y <<",";
        }
        cout <<endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >> n>>e>>k;
        for(int i=0;i<e;i++){
           cin >> startPoint >> endPoint;
           adjList[startPoint].push_back(endPoint);
           adjList[endPoint].push_back(startPoint);
        }
        cin >> M1 >>M2;
        dfs(M1,1,distFromSource);
        dfs(M2,1,distFromDestination);
        // q=0;
        // for(auto x:distFromSource){
        //     cout <<x.first<<":"<< x.second<<", ";
        // }
        // cout <<endl;
        // for(auto x:distFromDestination){
        //     cout <<x.first<<":"<< x.second<<", ";
        // }
        // cout <<endl;
        
        cin >> qry;
        int l,r,val,index,cse=1;
        while(qry--){
            cin >> N1 >> N2;
            distFromSource2.clear();
            distFromDestination2.clear();
            dfs(N1,1,distFromSource2);
            dfs(N2,1,distFromDestination2);
        // for(auto x:distFromSource2){
        //     cout <<x.first<<":"<< x.second<<", ";
        // }
        // cout <<endl;
        // for(auto x:distFromDestination2){
        //     cout <<x.first<<":"<< x.second<<", ";
        // }
        // cout <<endl;
        
        for(int i=1;i<=n;i++){
            int d1=max(distFromSource[i]-1,distFromDestination[i]-1);
            int d2=max(distFromSource2[i]-1,distFromDestination2[i]-1);
            // db(d1+d2,i);
            if(d1+d2<=k){
                // db(i);
                ans++;
            }
        
        }

        }
        
        

        
      cout << ans<<endl;
    }
    return 0;
}