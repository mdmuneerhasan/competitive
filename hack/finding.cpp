/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 17:59:20 Wednesday 22-July:2020*/
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
int p[]={2,3,5,7,11,13,17,19,23,29 };
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s1="";

    for(int i=0;i<20;i++){
        s1=s1+"0";
    }



    for(int i=1;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            string num = s.substr(j,i);
            int n = stoi(num);
            if(n<2)continue;
            bool pr=1;
            for(int i=0;i<10;i++){
                if(p[i]==n){
                    break;
                }else if(n%p[i]==0){
                    pr=0;
                }
            }
          //io  db(num);

            for(int k=j;k<j+i;k++){
                if(s1[k]=='1')pr=0;
            }
            if(pr){
                ans++;
                
                for(int k=j;k<j+i;k++){
                    s1[k]='1';
                }
              //  db(s1,num,j,i);
            }
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