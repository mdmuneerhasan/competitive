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
vector<pair<int,int>> vec;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
bool comp(pair<int,int> p1,pair<int,int> p2){
  if(p1.second==p2.second){
    return p1.first>p2.first;
  }
  return p1.second<p2.second;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      cin >>n1;
      vec.clear();
      for(int q=0;q<n1;q++){
        cin >>startPoint>>endPoint;
        vec.push_back(make_pair(startPoint-endPoint
                              ,startPoint+endPoint));
      }
      sort(vec.begin(),vec.end(),comp);
      ans=1;cnt=vec[0].second;
      for(auto x:vec){
          if(cnt<=x.first){
            cnt=x.second;
            ans++;
          }
      }
      cout << n1-ans<<endl;
    }
    return 0;
}