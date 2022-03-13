/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 09:49:39 Thursday 03-September:2020*/
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
vector<int> vec1,vec2,vec3,primes;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
struct Node{
    int best;
    int sum;
    int bestRight;
    int bestLeft;
    Node(){
        best=0;
        bestLeft=0;
        bestRight=0;
        sum=0;
    }
};
vector<Node> tree;
vector<int> lazy;
void build(int start,int end,int node ){
    if(start==end){
        tree[node].best=vec1[start];
        tree[node].bestRight=vec1[start];
        tree[node].bestLeft=vec1[start];
        tree[node].sum=vec1[start];
        return;
    }
    int mid=(start+end)/2;
    build(start,mid,2*node+1);
    build(mid+1,end,2*node+2);
    tree[node].best=max({tree[2*node+1].sum+tree[2*node+2].sum,
           tree[2*node+1].bestRight+tree[2*node+2].sum,
           tree[2*node+1].sum+tree[2*node+2].bestLeft,     
           tree[2*node+1].bestRight+tree[2*node+2].bestLeft     
    });
    tree[node].sum=tree[2*node+1].sum+tree[2*node+2].sum;
    tree[node].bestLeft=max({
        tree[2*node+1].bestRight,
        tree[2*node+1].sum
    });
    
    tree[node].bestRight=max({
        tree[2*node+2].bestLeft,
        tree[2*node+2].sum
    });
    

}
Node query(int start,int end ,int node ,int l,int r){
    Node n1,n2,n3;
    if(start>end || end<l || start>r)return n1;
    if(start>=l && end<=r){
        db(tree[node].best);
        return tree[node];
    }
    int mid=(start+end)/2;
    n1=query(start,mid,2*node+1,l,r);
    n2=query(mid+1,end,2*node+2,l,r);

    n3.best=max({n1.sum+n2.sum,
           n1.bestRight+n2.sum,
           n1.sum+n2.bestLeft,     
           n1.bestRight+n2.bestLeft     
    });
    n3.sum=n1.sum+n2.sum;
    n3.bestLeft=max({
        n1.bestRight,
        n1.sum
    });
    
    n3.bestRight=max({
        n2.bestLeft,
        n2.sum
    });


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
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    cin >>n1;
    vec1.clear();
    vec1.resize(n1,0);
    tree.clear();
    tree.resize(4*n1+5);
    for(int q=0;q<n1;q++){
      cin >> vec1[q];
    }
    build(0,n1-1,0);
    
    cin >> k;

    for(int i=0;i<k;i++){
        cin >> x >> y;
        cout << query(0,n1-1,0,x-1,y-1).best<<endl;
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