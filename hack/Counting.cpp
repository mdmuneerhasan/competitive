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
unordered_map<int,int> range;
unordered_map<int,int> counter;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
          cin >> n1>>k;
          for(int q=0;q<n1;q++){
              cin >> startPoint >> endPoint;
              range[startPoint]=-1;
              range[endPoint]=1;
          }
          for(int i=0;i<10;i++){
              db(i,range[i]);
          }
          int i=0;
          while(k--){
              cin >> startPoint>>endPoint;
              ans=0;
              for(;i<=endPoint;i++){
              counter[i]=counter[i-1]+range[i];
              }
              cout << counter[endPoint]-counter[startPoint]<<endl;
          }
    }
    return 0;
}