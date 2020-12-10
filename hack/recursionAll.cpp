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
vector<string> vec;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
void solve(string s1,string s2){
    if(s1.empty()){
        vec.push_back(s2);
        return ;
    }
    solve(s1.substr(1),s2);
    solve(s1.substr(1),s2+s1[0]);
 }
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        string s;
        vec.clear();
        cin >> s;
        solve(s,"");

        sort(vec.begin(),vec.end());
for(auto x:vec){
cout << x<<endl;
}

        
      
    }
    return 0;
}