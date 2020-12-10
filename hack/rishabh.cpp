/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 00:06:39 Sunday 17-May:2020*/
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
    n1=5;
    vec1.clear();
    vec1.resize(n1,0);
    for(int q=0;q<n1;q++){
      cin >> vec1[q];
    }
    vec2.resize(3);

    cin >> n;
    int stones,beauty;
    for(int i=0;i<n;i++){
        cin >> stones >> beauty;
        if(abs(beauty)>2*stones ){
            cout << -1<<endl;
            continue;
        }
        if(beauty>0){
            vec2[0]=vec1[2];
            vec2[1]=vec1[3];
            vec2[2]=vec1[4];
        }else{
            beauty*=-1;
            vec2[0]=vec1[2];
            vec2[1]=vec1[1];
            vec2[2]=vec1[0];

        }
        int one=beauty;
        int two=beauty/2;
        if(two>stones){
            cout << -1<<endl;
        }else if(two==stones){
            cout << two*vec2[2]<<endl;
        }else if(two<stones){
            if(2*vec2[1]<vec2[2]){
                one=beauty;
                if(one<stones){
                    cout << one*vec2[1]+(stones-one)*vec2[0]<<endl;
                }else if(one==stones){
                    cout << one*vec2[1]<<endl;
                }else{
                    two=beauty-stones;
                    one=stones-two;
                cout << two*vec2[2]+one*vec2[1]+vec2[0]*(stones-two-one)<<endl;

                }
            }else{
                one=beauty-2*two;
                cout << two*vec2[2]+one*vec2[1]+vec2[0]*(stones-two-one)<<endl;
            }
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