/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 22:57:04 Friday 24-April:2020*/
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
    Node * one, * zero;
    int cnt;
    Node(){
        one=NULL;
        zero=NULL;
    }
};
Node * insert(Node * node,int val){
    if(node==NULL){
        node=new Node();
    }
    if(val==0){
        node->cnt=1;
        return node;
    }
    if(val&1){
        node->one=insert(node->one,val/2);
    }else{
        node->zero=insert(node->zero,val/2);
    }
    return node;
}
int query(Node * node,int val){
    if(node==NULL){
        return 0;
    }
    if(val&1){
        return query(node->zero,val/2)+node->cnt;
    }else{
        return query(node->one,val/2)
        +query(node->zero,val/2)+node->cnt;
    }
}
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    
    cin >>n1;
    vec1.clear();
    vec1.resize(n1,0);
    Node * root=NULL;
    for(int q=0;q<n1;q++){
      cin >> k;
      vec1[q]=k;
      root=insert(root,k);
      ans=0;
      b=1;
      cout << k << " ";
      while(k){
          ans=ans+k%2*b;
          b*=10;
          k/=2;
      }
      cout << ans<<endl;
    }

    ans=0;

    for(int i=0;i<n1;i++){
        ans+=query(root,vec1[i]);
        db(ans,vec1[i]);
    }

    cout << ans<<endl;



    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >>t;    
    while (t--)Muneer();
    return 0;
}