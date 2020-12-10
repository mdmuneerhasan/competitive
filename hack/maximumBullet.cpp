#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<int> vec;
vector<int> vec2;
int n,n1,n2,startPoint,k2,k1,endPoint,ans=0,cnt=0,q=0,qry=0;
int solve(int index,bool bablu,int first,int sec,int start){
    if(index==n1)return 0;
    int a=0,b=0;
    if(!start){
        b=max(solve(index+1,bablu,first,sec,start)
        ,solve(index,bablu,first,sec,1));
    }else{
    if(bablu){
        if(first==0)return 0;
        a=solve(index+1,0,first-1,sec,1)+vec[index];
    }else{
        if(sec==0)return 0;
        a=solve(index+1,1,first,sec-1,1)+vec2[index];
    }

    }
    return max(a,b);

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >>n1>>k1>>k2;
        vec.clear();
        vec.resize(n1,0);
        for(int q=0;q<n1;q++){
          cin >> vec[q];
        }
        vec2.clear();
        vec2.resize(n1,0);
        for(int q=0;q<n1;q++){
          cin >> vec2[q];
        }
        cout << max(solve(0,0,k1,k2,0),solve(0,1,k1,k2,0))<<endl;
        
    }
    return 0;
}