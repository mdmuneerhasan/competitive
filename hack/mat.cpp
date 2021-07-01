/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 04:01:54 Monday 19-April:2021*/
#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define SF(v)           sort(v.begin(),v.end())
#define UP(x)           for(int i=0;i<x.size();i++){if(x[i]<='z' && x[i]>='a')x[i]=char(x[i]-'a'+'A');}
#define LO(x)           for(int i=0;i<x.size();i++){if(x[i]<='Z' && x[i]>='A')x[i]=char(x[i]-'A'+'a');}
#define MAXHEAP         priority_queue<int>
#define MINHEAP         priority_queue<int, vector<int>, greater<int> >
#define SETBIT(x)       __builtin_popcountll(x)
#define ZEROBIT(x)      __builtin_ctzll(x)
#define PS(x,y)         fixed<<setprecision(y)<<x
#define MOD             1000000007
#define N               100000
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args) {    const char* comma = strchr(names + 1, ',');    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
struct Node{
    int a11,a12,a21,a22;
    Node(){
        a11=1;
        a12=0;
        a21=0;
        a22=1;
    }
};
vector<Node> vec1,vec2,vec3,primes;
int row,col;vector<vector<int>> vec;
int mod,n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
string s, s1 ,s2;


vector<Node> tree;
vector<int> lazy;
Node mult(Node a,Node b){
    Node c;
    c.a11=((a.a11*b.a11)%mod+(a.a12*b.a21)%mod)%mod;
    c.a12=((a.a11*b.a12)%mod+(a.a12*b.a22)%mod)%mod;
    c.a21=((a.a21*b.a11)%mod+(a.a22*b.a21)%mod)%mod;
    c.a22=((a.a21*b.a12)%mod+(a.a22*b.a22)%mod)%mod;
    return c;
}
void build(int start,int end,int node ){
    if(start==end){
        tree[node]=vec1[start];
        return;
    }
    int mid=(start+end)/2;
    build(start,mid,2*node+1);
    build(mid+1,end,2*node+2);
    tree[node]=mult(tree[2*node+1],tree[2*node+2]);
}
// void update(int start,int end ,int node ,int l,int r,int val){
//     if(start>end || end<l || start>r)return;
//     if(lazy[node]!=0){
//         int x=lazy[node];
//         tree[node]+=(end-start+1)*x;
//         lazy[2*node+1]=x;
//         lazy[2*node+2]=x;
//     }
//     if(start>=l && end<=r){
//         tree[node]+=val*(end-start+1);
//         if(start!=end){
//         lazy[2*node+1]=val;
//         lazy[2*node+2]=val;}
//         return;
//     }
//     int mid=(start+end)/2;
//     update(start,mid,2*node+1,l,r,val);
//     update(mid+1,end,2*node+2,l,r,val);
//     tree[node]=(tree[2*node+1]+tree[2*node+2]);

// }
Node query(int start,int end ,int node ,int l,int r){
    Node n1;
    if(start>end || end<l || start>r)return n1;
    
    if(start>=l && end<=r){
        return tree[node];
    }
    int mid=(start+end)/2;
    return mult(
    query(start,mid,2*node+1,l,r),
    query(mid+1,end,2*node+2,l,r));
}
// void print(int par=0,string indent="",string child=""){
//     if(par>=tree.size())return;
//     cout <<"\n"<<indent<<"`---"<<tree[par];
//     if(child.size()!=0)cout<<'{'<<child<<"}";
//     print(2*par+1,"\t"+indent,"l");
//     print(2*par+2,"\t"+indent,"r");
//     return;
// }
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,a=0,b=0;
    
    cin >>mod>>n1>>qry;
    vec1.clear();
    vec1.resize(n1);
    for(int q=0;q<n1;q++){
      cin >> vec1[q].a11>>vec1[q].a12>>vec1[q].a21>>vec1[q].a22;
    }
    tree.resize(4*n1+2);
    build(0,n1-1,0);

    for(int i=0;i<qry;i++){
        cin>> stt >> ent;
        Node n=query(0,n1-1,0,stt-1,ent-1);
        cout << n.a11<<" "<<n.a12<<endl;
        cout << n.a21<<" "<<n.a22<<endl;
        cout <<endl;
    }
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >>t;    
    while (t--)Muneer();
    return 0;
}