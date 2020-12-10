/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 19:13:01 Monday 18-May:2020*/
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

void solve(int start,int end){
    set<pair<int,PII>> q;
    q.insert({end-start+1,{start,end}});
    while(!q.empty()){
        auto x=*q.begin();
        q.erase(q.begin());
        PII y=x.second;
        start=y.first;
        end=y.second;
    if(start==end){
        vec1[start]=++n3;
    }else  if((end-start+1)%2==1){
        int mid=(start+end)/2;
        vec1[mid]=++n3;
        if(mid-1>=start)
        q.insert({mid-start,{start,mid-1}});
        if(mid+1<=end)
        q.insert({end-mid,{mid+1,end}});
    }else{
        int mid=(start+end-1)/2;
        vec1[mid]=++n3;
        if(mid-1>=start)
       q.insert({mid-start,{start,mid-1}});
        if(mid+1<=end)
        q.insert({end-mid,{mid+1,end}});
    }
    }
}
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    cin >> n;
    n3=0;
    vec1.clear();
    vec1.resize(n+5);
    solve(0,n-1);
    for(int i=0;i<n;i++){
        cout<<vec1[i]<<" ";
    }
    cout <<endl;
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    cin >>t;    
    while (t--)Muneer();
    return 0;
}