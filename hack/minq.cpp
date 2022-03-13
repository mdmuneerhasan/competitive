/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 20:37:02 Wednesday 02-September:2020*/
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
#define MOD             1000000007
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args) {    const char* comma = strchr(names + 1, ',');    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
vector<int> vec1,tree,vec3,primes;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
void build(int start,int end,int node){
    if(start==end){
        tree[node]=vec1[start];
        return;
    }
    int mid =(start+end)/2;
    build(start,mid,2*node +1 );
    build(mid +1 ,end, 2*node +2);
    tree[node]=min(tree[2*node+1],tree[2*node+2]);
}
void update(int start,int end,int node,int index,int val){
    if(start>index|| end <index || start>end)return;
    if(start==end){
        tree[node]=val;
        return;
    }
    int mid=(start+end)/2;
        update(mid+1,end,2*node+2,index,val);
        update(start,mid,2*node+1,index,val);
    
    tree[node]=min(tree[2*node+1],tree[2*node+2]);
}
int query(int start,int end,int node,int l,int r){
    if(start>r || end<l || start>end){
        return INF;
    }
    if(start>=l && end<=r){
        return tree[node];
    }
    int mid=(start+end)/2;
    return min(query(start,mid,2*node+1,l,r),query(mid+1,end,2*node+2,l,r));

}
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    cin >>n1>>k;
    vec1.clear();
    vec1.resize(n1,0);
    tree.clear();
    tree.resize(4*n1+5);
    for(int q=0;q<n1;q++){
      cin >> vec1[q];
    }
    build(0,n1-1,0);

    for(int i=0;i<k;i++){
        cin >>n2;
        if(n2==1){
            cin >> x>> y;
            int ans=query(0,n1-1,0,x-1,y-1);
            cout << ans<<endl;
        }else{
            cin >> x>> y;
            update(0,n1-1,0,x-1,y);
        }
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