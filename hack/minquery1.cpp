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
vector<int> tree;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,qry=0;
void build(int start,int end,int node ){
    if(start==end){
        tree[node]=vec[start];
        return;
    }
    int mid=(start+end)/2;
    build(start,mid,2*node+1);
    build(mid+1,end,2*node+2);
    tree[node]=min(tree[2*node+1],tree[2*node+2]);
}
void update(int start,int end ,int node ,int index,int val){
    if(start>end || end<index || start>index)return;
    if(start==end){
        tree[node]=val;
        return;
    }
    int mid=(start+end)/2;
    update(start,mid,2*node+1,index,val);
    update(mid+1,end,2*node+2,index,val);
    tree[node]=min(tree[2*node+1],tree[2*node+2]);

}
int query(int start,int end ,int node ,int l,int r){
    if(start>end || end<l || start>r)return INT_MAX;
    if(start>=l && end<=r){
        return tree[node];
    }
    int mid=(start+end)/2;
    return min(
    query(start,mid,2*node+1,l,r),
    query(mid+1,end,2*node+2,l,r));
}
void print(int par=0,string indent="",string child=""){
    if(par>=tree.size())return;
    cout <<"\n"<<indent<<"`---"<<tree[par];
    if(child.size()!=0)cout<<'{'<<child<<"}";
    print(2*par+1,"\t"+indent,"l");
    print(2*par+2,"\t"+indent,"r");
    return;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >>n1>>qry;
        vec.clear();
        vec.resize(n1,0);
        tree.clear();
        tree.resize(4*n1+5,0);
        for(int q=0;q<n1;q++){
          cin >> vec[q];
        }
        build(0,n1-1,0);

              ans=0;
      for(int i=0;i<n1;i++){
          for(int j=i+1;j<n1;j++){
            if(vec[i]+vec[j]+query(0,n1-1,0,i,j)<qry)ans++;
            cout <<vec[i]<<endl;
          }
      }
      cout << ans<<endl;


      
    }
    return 0;
}