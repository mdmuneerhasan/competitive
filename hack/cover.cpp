#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007
stringstream vin,vout;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<pair<int,int>> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;
vector<int> vec2;
vector<pair<int,int>> tree;
vector<int> lazy;
void build(int start,int end,int node ){
    if(start==end){
        tree[node]=vec[start];
        return;
    }
    int mid=(start+end)/2;
    build(start,mid,2*node+1);
    build(mid+1,end,2*node+2);
    
}

int query(int start,int end ,int node ,pair<int,int> x){
    if(start==end){
      
        return (abs(tree[node].first-x.first)%MOD*max(tree[node].second,x.second)%MOD)%MOD;
    }
    int mid=(start+end)/2;
    int a=(query(start,mid,2*node+1,x)+
    query(mid+1,end,2*node+2,x))%MOD;
    return a%MOD;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
      cin >>n1;
      vec.clear();
      vec.resize(n1);
      tree.clear();
      tree.resize(4*n1+5);
      for(int q=0;q<n1;q++){
        cin >> vec[q].first;
      }
      for(int q=0;q<n1;q++){
        cin >> vec[q].second;
      }
      cout <<endl;
      build(0,n1-1,0);
      ans=0;
      for(int i=0;i<n1;i++){
        ans+=query(0,n1-1,0,vec[i])%MOD;
      }
      cout << ans/2<<endl;
      
    }
    return 0;
}