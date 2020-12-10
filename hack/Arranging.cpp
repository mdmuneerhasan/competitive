/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 11:21:52 Thursday 16-April:2020*/
#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define sf(v)           sort(v.begin(),v.end())
#define ff              first
#define ss              second
#define mp              make_pair
#define pii             pair<int, int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int, vi, greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args) {    const char* comma = strchr(names + 1, ',');    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
vector<int> vec1,vec2,vec3,primes;
int n,n1,n2,startPoint,k=0,x=0,y=0,z=0,endPoint,ans=0,cnt=0,q=0,qry=0;
vector<int> tree;
vector<int> lazy;
void update(int start,int end ,int node ,int in,int val){
    if(start>end || end<in || start>in)return;

    if(start==end){
        tree[node]=max(val,tree[node]);
        return;
    }
    int mid=(start+end)/2;
    update(start,mid,2*node+1,in,val);
    update(mid+1,end,2*node+2,in,val);
    tree[node]=max(tree[2*node+1],tree[2*node+2]);

}
int query(int start,int end ,int node ,int l,int r){
    if(start>end || end<l || start>r)return 0;
    if(start>=l && end<=r){
        return tree[node];
    }
    int mid=(start+end)/2;
    return max(
    query(start,mid,2*node+1,l,r),
    query(mid+1,end,2*node+2,l,r));
}

void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    cin >>n1;
    vec1.clear();
    vec1.resize(n1+1,0);
    tree.clear();
    tree.resize(4*n1+5,0);
    for(int q=1;q<=n1;q++){
      cin >> vec1[q];
    }
    
    for(int i=1;i<=n1;i++){
      update(1,n1,0,vec1[i],query(1,n1,0,1,vec1[i])+1);


    }
    cout << n1-query(1,n1,0,1,n1)<<endl;
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >>t;    
    while (t--)Muneer();
    return 0;
}