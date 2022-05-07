/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 02:32:34 Sunday 27-March:2022*/
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
int row,col;vector<vector<int > > vec;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
string s, s1 ,s2;
struct Node{
    int data;
    Node * l , * r;
    Node(int l){
        data = l;
        this->l=NULL;
        this->r = NULL;
    }
};
map<int,pair<int,int > > dp;
Node * build(Node * root){
    
    queue<Node *> q;
    q.push(root);
    int l,r;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        cin >> l >> r;
      // db(l,r);
        if(l!=-1){
            x->l=new Node(l);
            q.push(x->l);
        }
        if(r!=-1){
            x->r=new Node(r);
            q.push(x->r);
        }

    }

    return root;
}
void print(Node * root,int lev=0,int d=0){
    
    
    if(root == NULL)return;
    if(dp.count(d)){
        if(lev<=dp[d].second){
            dp[d].first=root->data;
            dp[d].second = lev;
        }

    }else{
    dp[d].first=root->data;
    dp[d].second = lev;

    }

    print(root->l,lev-1,d+1);
    print(root->r,lev+1,d+1);


}
void Muneer(){
    int x;
    
    cin >> x;

    Node * root = build(new Node(x));

  
    print(root);
    for(auto x:dp){
        cout << x.second.first <<" ";
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