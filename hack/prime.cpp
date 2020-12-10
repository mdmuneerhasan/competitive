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
vector<bool> sev;
int n=1000000,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    sev.resize(n+1,0);
    for(int i=2;i<=n;i++){
        if(sev[i]==0){
            vec.push_back(i);
            for(int j=i*i;j<=n;j+=i){
                sev[j]=1;
            }
        }
    }
    
    cin >>t;    while (t--)
    {
      cin >> startPoint >> endPoint;
      ans=0;
      for(int i=0;vec[i]<=endPoint;i++){
        if(vec[i]>=startPoint)ans++;
        // db(vec[i]);
      }
      cout << ans<<endl;
      
    }
    return 0;
}