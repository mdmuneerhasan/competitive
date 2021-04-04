/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 16:09:33 Sunday 04-April:2021*/
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


string solve(int N,vector<int> vec1 ,vector<int> vec2 ,int k){
    int sum=0;


    for(int i=0;i<n1;i++){
        sum+=vec1[i]*vec2[i];
    }

    int temp=sum,n1=0,n2=0;
    vector<int> cpt(vec1);
    while(temp>k){
        int j=0;
        for(int i=0;i<cpt.size();i++){
            if(cpt[i]*vec2[i]-cpt[i]/2*vec2[i]>cpt[j]*vec2[j]-cpt[j]/2*vec2[j]){
                j=i;
            }
        }

        temp=temp-cpt[j]*vec2[j]+cpt[j]/2*vec2[j];
        cpt[j]/=2;
        n1++;
    }

    // db(temp,n1);
    vector<int> cpt2(vec2);
    temp=sum;

    while(temp>k){
        int j=0;
        for(int i=0;i<cpt2.size();i++){
            if(cpt2[i]*vec1[i]>cpt2[j]*vec1[j]){
                j=i;
            }
        }

        temp=temp-cpt2[j]*vec1[j]+cpt2[j]/2*vec1[j];
        cpt2[j]/=2;
        n2++;
    }
    

    // db(temp,n2);

    string ans ="Tie";
    if(n1<n2){
        ans="Alice";
    }else if(n1>n2){
        ans="Bob";
    }


    return ans;
}
void Muneer(){

    
    cin >>n1;
    vec1.clear();
    vec1.resize(n1,0);
    for(int q=0;q<n1;q++){
      cin >> vec1[q];
    }

    n2=n1;
    vec2.clear();
    vec2.resize(n2,0);
    for(int q=0;q<n2;q++){
      cin >> vec2[q];

    }
    cin >>k;

    cout << solve(n1,vec1,vec2,k)<<endl;


    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    cin >>t;    
    while (t--)Muneer();
    return 0;
}