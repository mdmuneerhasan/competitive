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
struct Node{
    int preSum,sufSum,total,maxSum;
    Node(){
        preSum=INT_MIN;
        sufSum=INT_MIN;
        total=INT_MIN;
        maxSum=INT_MIN;
    }
};
vector<int> vec;
vector<Node> tree;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,qry=0;
void build(int start,int end,int node ){
    if(start==end){
        tree[node].preSum=vec[start];
        tree[node].sufSum=vec[start];
        tree[node].maxSum=vec[start];
        tree[node].total=vec[start];
        return;
    }
    int mid=(start+end)/2;
    build(start,mid,2*node+1);
    build(mid+1,end,2*node+2);
    Node left=tree[2*node+1];
    Node right=tree[2*node+2];
    tree[node].sufSum=max({right.sufSum,right.total+left.sufSum});
    tree[node].preSum=max({left.preSum,left.total+right.preSum});
    tree[node].total=right.total+left.total;
    tree[node].maxSum=max({right.maxSum,left.maxSum,left.sufSum+right.preSum});
}
Node q(int start,int end ,int node ,int l,int r){
    Node left,right,n3;
    if(start>end || end<l || start>r){return n3;}
    if(start>=l && end<=r){
        return tree[node];
    }
    int mid=(start+end)/2;

    left=q(start,mid,2*node+1,l,r);
    right=q(mid+1,end,2*node+2,l,r);
    n3.sufSum=max({right.sufSum,right.total+left.sufSum});
    n3.preSum=max({left.preSum,left.total+right.preSum});
    n3.total=right.total+left.total;
    n3.maxSum=max({right.maxSum,left.maxSum,left.sufSum+right.preSum});
    return n3;
}
// void print(int par=0,string indent="",string child=""){
//     if(par>=tree.size())return;
//     cout <<"\n"<<indent<<"`---"<<tree[par];
//     if(child.size()!=0)cout<<'{'<<child<<"}";
//     print(2*par+1,"\t"+indent,"l");
//     print(2*par+2,"\t"+indent,"r");
//     return;
// }
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >>n1;
        vec.clear();
        vec.resize(n1,0);
        tree.clear();
        tree.resize(4*n1+5);
        for(int q=0;q<n1;q++){
          cin >> vec[q];
        }
        build(0,n1-1,0);
        cin >>qry;
        int l,r,val,index,cse=1;
        while(qry--){
           cin >>l>>r;
        cout <<    q(0,n1-1,0,l-1,r-1).maxSum<<endl;

        }
      
    }
    return 0;
}