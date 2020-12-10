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
vector<int> vec;


void Prof(int n){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    if(n==0){return;}

    vec.clear();
    vec.resize(n,0);
    for(int q=0;q<n;q++){
      cin >> vec[q];
    }
    vector<int> v(vec);

    sort(v.begin(),v.end());

    stack<int> st;

    int j=0;
    bool valid=true;


    for(int i=0;i<n;i++){
        if(st.size()>0 && st.top()==v[i]){

            }else {
                while(j<n &&vec[j]!=v[i]){
                    if( st.size()>0 && st.top()<vec[j]){
                        valid=false;
                    }
                    st.push(vec[j]);
                    j++;
                }
                
        }
        if(j<n &&vec[j]==v[i] )j++;

    
    }

    if(valid){
        cout << "yes"<<endl;
    }else{
        cout << "no"<<endl;
    }
    
    
    
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    int n=t;
    while (t){
        Prof(n);
        cin >>n;
        t=n;
    }
    return 0;
}