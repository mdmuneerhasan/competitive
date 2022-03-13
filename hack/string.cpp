/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 10:23:08 Sunday 30-August:2020*/
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
string pattern,givenString;
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    getline(cin,givenString);
    getline(cin,pattern);

    
    int startIndex=-1,endIndex=-1,j=0;
    n1=givenString.size();
    n2=pattern.size();

    int freqGiven[2800],freqPattern[2090];

    memset(freqGiven,0,sizeof(freqGiven));
    memset(freqPattern,0,sizeof(freqPattern));

    for(int i=0;i<n2;i++){
        freqPattern[pattern[i]]++;
    }
    int sz=n1;
    for(int i=0;i<n1;i++){
        int in=givenString[i];
        freqGiven[in]++;
        if(freqPattern[in]>0 && freqGiven[in]<=freqPattern[in]){
            cnt++;
            // db(cnt,i,in,freqPattern[in]);
            if(cnt>=n2){
                while(cnt>=n2){
                    if(i-j+1<sz){
                        sz=i-j+1;
                        startIndex=j;
                        endIndex=i;
                        // db(sz);
                    }
                    int in2=givenString[j];
                    freqGiven[in2]--;
                    j++;
                    if(freqPattern[in2]>0 && freqGiven[in2]<freqPattern[in2]){
                        cnt--;
                    }
                    // db(i,j,cnt,givenString[i],givenString[j]);
                }

            }
        }
    }
    if(endIndex==-1){
        cout << "No String"<<endl;
    }else
    cout << givenString.substr(startIndex,endIndex-startIndex+1)<<endl;


    
    
    
    
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >>t;    
    while (t--)Muneer();
    return 0;
}