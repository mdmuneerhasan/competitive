/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 19:52:45 Saturday 09-May:2020*/
#include<bits/stdc++.h>
using namespace std;
#define SF(v)           sort(v.begin(),v.end())
#define F               first
#define S               second
#define UP(x)           for(long double i=0;i<x.size();i++){if(x[i]<='z' && x[i]>='a')x[i]=char(x[i]-'a'+'A');}
#define LO(x)           for(long double i=0;i<x.size();i++){if(x[i]<='Z' && x[i]>='A')x[i]=char(x[i]-'A'+'a');}
#define MP              make_pair
#define PII             pair<long double, long double>
#define MAXHEAP         priority_queue<long double>
#define MINHEAP         priority_queue<long double, vector<long double>, greater<long double> >
#define SETBIT(x)       __builtin_popcountll(x)
#define ZEROBIT(x)      __builtin_ctzll(x)
#define INF             1e18
#define PS(x,y)         fixed<<setprecision(y)<<x
#define MOD             1000000007
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args) {    const char* comma = strchr(names + 1, ',');    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
vector<pair<long double,PII>> vec1,vec2,vec3,primes;
long double n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
long double solve(long double start,long double end,long double r){
    // db(start,end);
    if(start==end)return start;
    long double mid=(start+end)/2;
    if(vec1[mid].first<=r){
        // if(vec1[mid+1].first>r)return mid;
        return solve(mid+1,end,r);
    }else{
        return solve(start,mid,r);
    }
}
void Muneer(){
    long double ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    cin >>n1;
    vec1.clear();
    vec1.resize(n1);
    for(long double q=0;q<n1;q++){
      cin >> vec1[q].second.first;
      cin >> vec1[q].second.second;
      vec1[q].first=sqrt(vec1[q].second.first*vec1[q].second.first
                +vec1[q].second.second*vec1[q].second.second);
    }
    SF(vec1);
    cin >> n;
    for(long double i=0;i<n;i++){
        cin >> a;
        stt=0;ent=n1-1;
        while(stt<=ent){
            long double mid=(int)(stt+ent)/2;
            if(vec1[mid].F<a){
                ans=mid;
                stt=mid+1;
            }else{
                ent=mid-1;
            }
        }
        cout << ans+1<<endl;
    }
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long double t=1;
    // cin >>t;    
    while (t--)Muneer();
    return 0;
}