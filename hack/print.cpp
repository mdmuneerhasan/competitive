/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 20:25:26 Saturday 26-March:2022*/
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
    int d;
    Node * r;
    Node * l;
    Node(){
        l=NULL;
        r=NULL;
    }

};

Node * build(int l=0,int r=n1-1){
    
    Node * n =NULL;
    if(r==l){
        n=new Node();
        n->d = vec1[q++];

    }else if(r>l){
        int i;
        for(i=l;i<=r;i++){
            if(vec2[i]==vec1[q])break;
        }
        n=new Node();
        n->d = vec1[q++];

        n->l = build(l,i-1);

        n->r = build(i+1,r);

    }


return n;
}
void printD(Node * r, int dis){
    if(r==NULL)return;
    if(dis==0){
        cout << r->d<<" ";
        return;
    }
    printD(r->l,dis-1);
    printD(r->r,dis-1);

}
int print(Node * r,int target,int dis){
    if(r==NULL|| k<0)return -1;
    if(r->d==target){
        printD(r,dis);
        return 0;
    }
    int ret = print(r->l,target,dis);
    if(ret!=-1){

        if(ret+1==k){
            cout << r->d<<endl;
        }else{
            //print down
            printD(r->r,dis-ret-2);
        }
            return ret+1;

    }
    
    ret = print(r->r,target,dis);
    if(ret!=-1){

        if(ret+1==k){
            cout << r->d<<endl;
        }else{
            //print down
            printD(r->l,dis-ret-2);
        }
            return ret+1;

    }

    return -1;

}
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    
    cin >>n1;
    vec1.clear();
    vec1.resize(n1,0);
    for(int q=0;q<n1;q++){
      cin >> vec1[q];
    }

    n2=n1;

    vec2.clear();
    vec2.resize(n2,0);
    for(int q=0;q<n2;q++){
      cin >> vec2[q];
    }

    Node * root = build();
    
    cin >> x;
    while(x--){
        cin >> n>>k;
       print(root,n,k);
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