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
set<string> s;
void solve(int index,int sum ,string ans){
    if(index==n1){
        if(sum==0){
            if(s.count(ans)==0)cout << ans<<endl;
            s.insert(ans);
            }
            
        return;
    }
    if(sum>=vec[index])
    solve(index+1,sum-vec[index],ans+" "+to_string(vec[index]));
    solve(index+1,sum,ans);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >>n1;
        vec.clear();
        vec.resize(n1,0);
        for(int q=0;q<n1;q++){
          cin >> vec[q];
        }
        sort(vec.begin(),vec.end());
        cin >>k;
        solve(0,k,"");
      
    }
    return 0;
}