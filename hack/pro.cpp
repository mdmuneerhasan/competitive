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
void solve(string unprocessed,string processed){
    if(unprocessed.size()==0){
        cout << processed<<endl;
        return;
    }
    for(int i=0;i<unprocessed.size();i++){
        char s=unprocessed[i];
        solve(unprocessed.substr(0,i)+unprocessed.substr(i+1)
        ,processed+s);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      string s;
      cin >> s;
      solve(s,"");
      
    }
    return 0;
}