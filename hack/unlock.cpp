/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 11:56:54 Sunday 30-August:2020*/
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

void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    cin >>n1>>k;
    vec1.clear();
    unordered_map<int,int> dp;
    vec1.resize(n1,0);
    for(int q=0;q<n1;q++){
      cin >> vec1[q];
      dp[vec1[q]]=q;
    }
    vector<int> vec2(vec1);
    sort(vec1.begin(),vec1.end(),greater<>());

    for(int i=0;i<n1;i++){
        if(k && vec2[i]!=vec1[i]){
            k--;
        cout<<vec1[i] << " ";
            int v1=vec1[i];
            int v2=vec2[i];
            int i2=dp[vec1[i]];

            vec2[i]=v1;
            vec2[i2]=v2;
            dp[v1]=i;
            dp[v2]=i2;

            // db(i,k,vec2[i],v1);
            // db(i2,k,vec2[i2],v2);
        }
        else{
            cout <<vec2[i]<<" ";
        }

        // for(int i=0;i<n1;i++){
        //     cout << i <<":"<<vec2[i] << ", ";
        // }
        // cout <<endl;
        
        

    }
    cout <<endl;
    
    



    
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >>t;    
    while (t--)Muneer();
    return 0;
}