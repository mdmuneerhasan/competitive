/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 11:35:41 Tuesday 29-September:2020*/
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
vector<string> vec1,vec2,vec3,primes;
unordered_map<int,int> dp;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
bool check(string target,int i,int j,int di,int dj){
    if(target.empty())return 1;
    if(i<0 || j<0 || i>=m || j>=m)return 0;
    return target[0]==vec2[i][j] & check(target.substr(1),i+di,j+dj,di,dj);
}
bool solve(string target ,int i ,int j){
    if(check(target,i,j,1,-1))return 1;
    if(check(target,i,j,-1,1))return 1;

    if(check(target,i,j,-1,-1))return 1;
    if(check(target,i,j,-1,0))return 1;
    if(check(target,i,j,0,-1))return 1;

    if(check(target,i,j,1,1))return 1;
    if(check(target,i,j,0,1))return 1;
    if(check(target,i,j,1,0))return 1;

    return 0;
}
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    cin >>n1;
    vec1.clear();
    vec1.resize(n1);
    for(int q=0;q<n1;q++){
      cin >> vec1[q];
    }
    string s;

    cin >> m;
    for(int i=0;i<m;i++){
        cin >> s;
        vec2.push_back(s);
    }
    SF(vec2);
    for(int i=0;i<n1;i++){
        bool b=0;
        string target=vec1[i];
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(target[0]==vec2[i][j]){
                    if(solve(target,i,j)){
                        cout<<target<<" ";
                        b=1;
                    }
                }
                if(b)break;
            }
                if(b)break;
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