/* This code is submitted by Muneer Hasan
* Computer-science student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 20:18:41 Friday 04-December:2020*/
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
unordered_map<int,int> dp;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;

int solve(int n,string s){
    int sz=s.size();
    int arr[n][8];

    memset(arr,0,sizeof(arr));

    int r=0;
    for(int i=0;i<s.size()-1;i++){
        if(s[i+1]==' '){
            arr[r][s[i]-'A']=1;
            r=0;
            i++;
        }else{
            r=r*10+(s[i]-'0');
        }
    }
    // int cnt=0,fam=0;
    // for(int i=0;i<n;i++){
    //     cnt=0;
    //     for(int j=0;j<7;j++){
    //         if(arr[i][j]==0){
    //             cnt++;
    //             if(cnt==4){
    //                 cnt=0;
    //                 fam++;
    //             }
    //         }else{
    //             cnt=0;
    //         }
    //     }
    // }
    return 0;
}
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    string s;
    cin >> s;
    cin >> n;
    cout << solve(1,"")<<endl;
    
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >>t;    
    while (t--)Muneer();
    return 0;
}