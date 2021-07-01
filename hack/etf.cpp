/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 18:12:50 Tuesday 13-April:2021*/
#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define SF(v)           sort(v.begin(),v.end())
#define UP(x)           for(int i=0;i<x.size();i++){if(x[i]<='z' && x[i]>='a')x[i]=char(x[i]-'a'+'A');}
#define LO(x)           for(int i=0;i<x.size();i++){if(x[i]<='Z' && x[i]>='A')x[i]=char(x[i]-'A'+'a');}
#define MAXHEAP         priority_queue<int>
#define MINHEAP         priority_queue<int, vector<int>, greater<int> >
#define SETBIT(x)       __builtin_popcountll(x)
#define ZEROBIT(x)      __builtin_ctzll(x)
#define PS(x,y)         fixed<<setprecision(y)<<x
#define MOD             1000000007
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args) {    const char* comma = strchr(names + 1, ',');    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
vector<int> vec1,vec2,vec3,primes;
int row,col;vector<vector<int>> vec;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
string s, s1 ,s2;
const int N=1000001;
int seive[N]={0};


void Muneer(){
    int ans=0,cnt=0,x=0,y=0,a=0,b=0;

        
        for(int i=0;i<N;i++){
            seive[i]=i;
        }

        for(int i=2;i<N;i++){
        if(seive[i]==i){
            seive[i]=i-1;
            for(int j=2*i;j<N;j+=i){
                seive[j]=seive[j]*(i-1)/i;
            }
        }
    }

    // for(int i=0;i<100;i++){
    //     cout << i <<":"<<seive[i] << ", ";
    // }
    // cout <<endl;
    
    

    for(int i=1;i<N;i++){
        seive[i]+=seive[i-1];
    }




    
    // for(int i=0;i<100;i++){
    //     cout << i <<":"<<seive[i] << ", ";
    // }
    // cout <<endl;
    
    


    cin >> n;
    for(int i=0;i<n;i++){
        
        cin >> stt >> ent;

        cout << seive[ent]-seive[stt-1]<<endl;

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