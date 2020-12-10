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
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
set<int> dp;
void insert(int n,int cnt=8){
    if(n>1000000000000000000)return;
    dp.insert(n);
    insert(2*n,cnt*2);
    // insert(2*n+1,cnt*2);
    // insert(cnt+n,cnt*2);

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    int i=6;
    int m=1;
         insert(6);

    q=0;
    for(auto x:dp){
        cout <<q++<<":"<< x<<", ";
    }
    cout <<endl;
    


    // for(auto x:dp){
    //     cout <<x<<":"; con(x);cout<<"\n";
    // }
    // cout <<endl;

    

    //cin >>t;    while (t--)
    {
      //cin >> n;
      
    }
    return 0;
}