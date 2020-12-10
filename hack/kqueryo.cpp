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
struct Node{
    int val,count;
};
vector<vector<int>> tree;
int n;
vector<int> arr;
int k=1e9;
struct seg{
    void init(int n){
        tree.resize(4*n+5);
    }
    void build(){
        build(0,n-1,0);
    }
    void build(int start,int end,int node){
        if(start>=end){
            tree[node].push_back(arr[start]);
            return  ;
        }
        int mid=(start+end)/2;
        build(start,mid,2*node+1);
        build(mid+1,end,2*node+2);
        merge(tree[2*node+1].begin(),tree[2*node+1].end(),
                tree[2*node+2].begin(),tree[2*node+2].end(),
                back_inserter(tree[node]));
        return ;
    }
    int query(int item,int l,int r){
       return query(0,n-1,0,l,r,item);
    }
    int query(int start,int end,int node,int l,int r,int val){
        if(start>r || end<l ||start>end)return 0;
        if(start>=l&&end<=r){
            int ans=tree[node].size()-(upper_bound(tree[node].begin(),
            tree[node].end(),val)-tree[node].begin());
            return ans;
        }

        int mid=(start+end)/2;
        return query(start,mid,2*node+1,l,r,val)+query(mid+1,end,2*node+2,l,r,val);
    }
    

}s;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
    //   int n;
    //   cin >> n;
    
    cin >>n;
    arr.resize(n,0);
    for(int q=0;q<n;q++){
      cin >> arr[q];
    }
    s.init(n);
    s.build();
    cin >>t;
    int pre=0;
    while(t--){
        k=1e9;
      int l,r,k1;
      cin >> l >> r >>k1;
      l^=pre;
      r^=pre;
      k1^=pre;
      
     pre= s.query(k1,l-1,r-1);
     cout << pre<<endl;

    }



    }
    return 0;
}