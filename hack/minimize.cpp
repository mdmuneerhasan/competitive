/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 13:28:20 Thursday 01-October:2020*/
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
unordered_map<int,int> dp,dp2,dp3,dp4;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;

void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    cin >>n1;
    cin >>n2;
    vec1.clear();
    vec1.resize(n1,0);
    MINHEAP h1;
    MAXHEAP h2;
    for(int q=0;q<n1;q++){
      cin >> vec1[q];
    }

    vec2.clear();
    vec2.resize(n2,0);
    for(int q=0;q<n2;q++){
      cin >> vec2[q];
    }
    
    SF(vec1);
    SF(vec2);



    int iMul=1;


    for(int i=1;i<n1;i++){
        dp[vec1[i]]=dp[vec1[i-1]]+(vec1[i]-vec1[i-1])*iMul;
        iMul++;
    }
    iMul=1;
    for(int i=n1-2;i>=0;i--){
        dp2[vec1[i]]=dp2[vec1[i+1]]+(vec1[i+1]-vec1[i])*iMul;
        iMul++;
    }

    // for(int i=0;i<n1;i++){
    //   cout << i <<":"<<vec1[i]<<"-"<<dp[vec1[i]]<<"-"<<dp2[vec1[i]] << ", ";
    // }
    // cout <<endl;
    

    iMul=1;
    for(int i=1;i<n2;i++){
        dp3[vec2[i]]=dp3[vec2[i-1]]+(vec2[i]-vec2[i-1])*iMul;
        iMul++;
    }
    iMul=1;
    for(int i=n2-2;i>=0;i--){
        dp4[vec2[i]]=dp4[vec2[i+1]]+(vec2[i+1]-vec2[i])*iMul;
        iMul++;
    }

    // for(int i=0;i<n2;i++){
    //   cout << i <<":"<<vec2[i]<<"-"<<dp3[vec2[i]]<<"-"<<dp4[vec2[i]] << ", ";
    // }
    // cout <<endl;
    



    ans=INT_MAX;
    int i=0,j=0;
    int ll=0,ul=0;
    for(int i=0;i<n1;i++){
        while(vec1[i]>vec2[j])j++;
        if(ans>dp[vec1[i]]+dp4[vec2[j]]){
            ans=dp[vec1[i]]+dp4[vec2[j]];
            
        }
    
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