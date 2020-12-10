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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    // cin >>t;    while (t--)
    {
      cin >>n1;
      vec.clear();
      vec.resize(n1,0);
      int lis[n1],lds[n1];
      for(int q=0;q<n1;q++){
        cin >> vec[q];
      }
      for(int i=0;i<n1;i++){
        lis[i]=1;
      }
      for(int i=1;i<n1;i++){
        for(int j=0;j<i;j++){
          if(vec[i]>vec[j] && lis[i]<lis[j]+1)lis[i]=lis[j]+1;
        }
      }
      for(int i=0;i<n1;i++){
        lds[i]=1;
      }
      for(int i=n1-2;i>=0;i--){
        for(int j=n1-1;j>i;j--){
          if(vec[i]>vec[j] && lds[i]<lds[j]+1)lds[i]=lds[j]+1;
        }
      }
      // for(int i=0;i<n1;i++){
      //     cout << i <<":"<<lis[i] << ", ";
      // }
      // cout <<endl;
      // for(int i=0;i<n1;i++){
      //     cout << i <<":"<<lds[i] << ", ";
      // }
      // cout <<endl;
      
      
      
      ans=0;
      for(int i=0;i<n1;i++){
        ans=max(ans,lis[i]+lds[i]-1);
      }
      cout << ans<<endl;
      
      
      
    }
    return 0;
}