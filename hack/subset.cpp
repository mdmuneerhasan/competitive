/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
<<<<<<< HEAD
* 02:03:54 Wednesday 14-April:2021*/
=======
* 10:26:09 Tuesday 01-September:2020*/
>>>>>>> competitive/master
#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define SF(v)           sort(v.begin(),v.end())
<<<<<<< HEAD
#define UP(x)           for(int i=0;i<x.size();i++){if(x[i]<='z' && x[i]>='a')x[i]=char(x[i]-'a'+'A');}
#define LO(x)           for(int i=0;i<x.size();i++){if(x[i]<='Z' && x[i]>='A')x[i]=char(x[i]-'A'+'a');}
=======
#define F               first
#define S               second
#define UP(x)           for(int i=0;i<x.size();i++){if(x[i]<='z' && x[i]>='a')x[i]=char(x[i]-'a'+'A');}
#define LO(x)           for(int i=0;i<x.size();i++){if(x[i]<='Z' && x[i]>='A')x[i]=char(x[i]-'A'+'a');}
#define MP              make_pair
#define PII             pair<int, int>
>>>>>>> competitive/master
#define MAXHEAP         priority_queue<int>
#define MINHEAP         priority_queue<int, vector<int>, greater<int> >
#define SETBIT(x)       __builtin_popcountll(x)
#define ZEROBIT(x)      __builtin_ctzll(x)
<<<<<<< HEAD
=======
#define INF             1e18
>>>>>>> competitive/master
#define PS(x,y)         fixed<<setprecision(y)<<x
#define MOD             1000000007
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args) {    const char* comma = strchr(names + 1, ',');    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
vector<int> vec1,vec2,vec3,primes;
<<<<<<< HEAD
int row,col;vector<vector<int>> vec;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
string s, s1 ,s2;
// int dp[5][]
bool solve(int in,int sum ,bool taken){
    if(in==n1)return sum==0 && taken;

    return solve(in+1,sum,taken)|solve(in+1,sum+vec1[in],1);
}
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,a=0,b=0;
    
=======

void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
>>>>>>> competitive/master
    cin >>n1;
    vec1.clear();
    vec1.resize(n1,0);
    for(int q=0;q<n1;q++){
      cin >> vec1[q];
    }
<<<<<<< HEAD

    if(solve(0,0,0)){
        cout << "Yes" <<endl;
    }else{
        cout << "No" <<endl;
    }
    
=======
    if(solve(0,0)){
        cout << "Yes"<<endl;
    }else{
        cout << "No"<<endl;
    }
    
    
>>>>>>> competitive/master
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    cin >>t;    
    while (t--)Muneer();
    return 0;
}