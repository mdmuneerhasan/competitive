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
bool cmp(string s1,string s2){int i;
    for(i=0;i<s1.size()&&i<s2.size();i++){
        if(s1[i]>s2[i])return false;
        if(s1[i]<s2[i])return true;
    }
    return s1.size()>=s2.size();
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >>n1;
        vec.clear();
        vec.resize(n1);
        for(int q=0;q<n1;q++){
          cin >> vec[q];
        }
        sort(vec.begin(),vec.end(),cmp);
      for(auto x:vec){
          cout << x<<endl;
      }
      cout <<endl;
      
    }
    return 0;
}