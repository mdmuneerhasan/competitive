#include<bits/stdc++.h>
using namespace std;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
const int N=100005;
vector<int> values(N),subtree_sum(N),max_subtree(N);
vector<vector<int>> graph(N),directed_tree(N);

int dfs1(int a,int parent){
    int t=0;
    for(auto curnode:graph[a]){
        if(curnode!=parent){
            directed_tree[a].push_back(curnode);
            t+=dfs1(curnode,a);
        }
    }
    subtree_sum[a]=t+values[a];
    //sum of values on nodes in subtree a
    return t+values[a];
}

int dfs2(int a,int parent){
    int t=subtree_sum[a];
    for(auto curnode:graph[a]){
        if(curnode!=parent){
            t=max(t,dfs2(curnode,a));
        }
    }
    max_subtree[a]=t;
    return t;
} 

int32_t main(){
    //freopen("input.txt",  "r",  stdin);
    //freopen("output.txt", "w", stdout);

    int n;cin>>n;
    //containers are declared globally
    for(int i=1;i<=n;i++)cin>>values[i];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs1(1,0);
    //dfs to find subtree sum at each node and to get directed tree
    // from parent to child
    dfs2(1,0);
    //dfs to find maximum sum subtree in a particular subtree

    int ans=0;
    for(auto a:directed_tree){

        vector<int>all_values;
        
        for(auto b:a){
            all_values.push_back(max_subtree[b]);
        }
        sort(all_values.begin(),all_values.end());
        int q=0;
        for(auto x:all_values){
            cout <<q++<<":"<< x<<", ";
        }
        
        
        if(all_values.size()>1){
            ans=max(ans,all_values[all_values.size()-1]
                    +all_values[all_values.size()-2]);
            //max two subtree sums in all subtrees of a
        }


    }
    cout<<ans;
}