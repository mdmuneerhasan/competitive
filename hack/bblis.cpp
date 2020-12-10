#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
vector<int> lis;
int n1;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
      cin >>n1;
      v.resize(n1,0);
      lis.resize(n1,1);
      for(int q=0;q<n1;q++){
        cin >> v[q];
      }
      int ans=0;
      for(int i=0;i<n1;i++){
          for(int j=0;j<i;j++){
           if(v[j]<v[i] && lis[j]+1>lis[i]){
               lis[i]=lis[j]+1;
               ans=max(ans,lis[i]);
           }
          }      
      }
      cout << ans<<endl;
      

      
    }
    return 0;
}