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
vector<pair<int,pair<int,int>>> vec;
vector<pair<int,pair<int,int>>> vec2;
priority_queue<pair<int,pair<int,int>>> pq;
priority_queue<pair<int,pair<int,int>>> pq2;
int n,n1,n2,startPoint,k=0,endPoint,ans1=0,edgeCount=0,wt=0,cnt=0,q=0,qry=0;
int nodes,edges;
unordered_map<int,int> visited;
unordered_map<int,int> parent;
unordered_map<int,vector<pair<int,int>>> adjList;
unordered_map<int,list<pair<int,int>>> adjList2;
void show(){
	for(auto x:adjList2){
		for(auto y:x.second){
            edgeCount++;
            wt+=y.second;
		}
	}
    unordered_map<string,int> mark;
	for(auto x:adjList){
        auto z=adjList2[x.first];
		for(auto y:x.second){
           if(find(z.begin(),z.end(),y)==z.end()){
               if(mark[to_string(x.first)+"-"+to_string(y.first)]==0){
                   mark[to_string(x.first)+"-"+to_string(y.first)]=1;
                   mark[to_string(y.first)+"-"+to_string(x.first)]=1;
                   pq2.push(make_pair(y.second,make_pair(y.first,x.first)));
               }

           }
		}
	}
    
    
}
bool cmp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
    return a.first>=b.first;
}
int findPar(int x){
    if(parent[x]==0)return x;
    int k=findPar(parent[x]);
    parent[x]=k;
    return k;
}
int dfs(int src,int par){
    visited[src]=1;
    int ans=0;
    for(auto x : adjList[src]){
        pq.push(make_pair(x.second,make_pair(x.first,src)));
    }
    while(!pq.empty()){
        auto x=pq.top();
        pq.pop();
        if(visited[x.second.first]==0||visited[x.second.second]==0){
            adjList2[x.second.second].push_back(make_pair(x.second.first,x.first));
            adjList2[x.second.first].push_back(make_pair(x.second.second,x.first));
            if(visited[x.second.first]==0)ans+=dfs(x.second.first,src);
            else if(visited[x.second.second]==0)ans+=dfs(x.second.second,src);
            
        }
    }
    return ans+1;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t;
	//cin >>t;    while (t--)
	{
		adjList.clear();
		visited.clear();
		cin >>nodes>>edges>>cnt;
		for(int i=0;i<edges;i++){
				cin >> startPoint >> endPoint>>k;
				adjList[startPoint].push_back(make_pair(endPoint,k));
				adjList[endPoint].push_back(make_pair(startPoint,k));
                ans1+=k;
		} 
        
        dfs(1,-1);
        show();

        edgeCount/=2;
        wt/=2;


        while(ans1-wt>cnt){
            auto x=pq2.top();

            wt+=x.first;
            edgeCount++;

            pq2.pop();
            
        }
	    cout <<edges- edgeCount<<endl;
        cout << ans1-wt<<endl;
      
	}
	return 0;
}
