/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 20:20:38 Friday 25-September:2020*/
#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define SF(v)           sort(v.begin(),v.end())
#define F               first
#define S               second
#define UP(x)           for(int i=0;i<x.size();i++){if(x[i]<='z' && x[i]>='a')x[i]=char(x[i]-'a'+'A');}
#define LO(x)           for(int i=0;i<x.size();i++){if(x[i]<='Z' && x[i]>='A')x[i]=char(x[i]-'A'+'a');}
#define MP              make_pair
#define PII             pair<int, int>
#define MAXHEAP         priority_queue<int>
#define MINHEAP         priority_queue<int, vector<int>, greater<int> >
#define SETBIT(x)       __builtin_popcountll(x)
#define ZEROBIT(x)      __builtin_ctzll(x)
#define INF             1e18
#define PS(x,y)         fixed<<setprecision(y)<<x
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
int MOD=1;
template <typename Arg1>void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args) {    const char* comma = strchr(names + 1, ',');    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
unordered_map<int,int> dp;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
struct Node{
    int a,b;
    int c,d;
    Node(){
        a=1;b=0;
        c=0;d=1;
    }
};
vector<Node>tree;
vector<Node>vec1,vec2,vec3,primes;
void build(int start,int end,int node ){
    if(start==end){
        tree[node]=vec1[start];
        return;
    }
    int mid=(start+end)/2;
    build(start,mid,2*node+1);
    build(mid+1,end,2*node+2);
    Node A=tree[2*node+1];
    Node B=tree[2*node+2];
    tree[node].a=((A.a*B.a)%MOD+(A.b*B.c)%MOD)%MOD;
    tree[node].b=((A.a*B.b)%MOD+(A.b*B.d)%MOD)%MOD;
    tree[node].c=((A.c*B.a)%MOD+(A.d*B.c)%MOD)%MOD;
    tree[node].d=((A.c*B.b)%MOD+(A.d*B.d)%MOD)%MOD;
}
Node query(int start,int end ,int node ,int l,int r){
    Node n1,A,B;
    if(start>end || end<l || start>r)return n1;
    if(start>=l && end<=r){
        return tree[node];
    }
    int mid=(start+end)/2;
    A=query(start,mid,2*node+1,l,r);
    B=query(mid+1,end,2*node+2,l,r);
    n1.a=((A.a*B.a)%MOD+(A.b*B.c)%MOD)%MOD;
    n1.b=((A.a*B.b)%MOD+(A.b*B.d)%MOD)%MOD;
    n1.c=((A.c*B.a)%MOD+(A.d*B.c)%MOD)%MOD;
    n1.d=((A.c*B.b)%MOD+(A.d*B.d)%MOD)%MOD;
    return n1;
}

void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    cin>>MOD>>n1>>q;
    vec1.clear();
    vec1.resize(n1);
    tree.clear();
    tree.resize(4*n1+5);
    for(int q=0;q<n1;q++){
      cin >>vec1[q].a>>vec1[q].b>>vec1[q].c>>vec1[q].d;
    }
    build(0,n1-1,0);

    for(int i=0;i<q;i++){
        cin >> stt >> ent;
        Node n=query(0,n1-1,0,stt-1,ent-1);
        cout << n.a<<" "<<n.b<<endl;
        cout << n.c<<" "<<n.d<<endl;
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