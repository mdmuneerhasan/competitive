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
int MOD=1000000007;
vector<int> vec;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    // cin >>t;    while (t--)
    {
          cin >> n1;
          int arr[n1];
          for(int i=0;i<n1;i++){
            cin >> arr[i];
          }
          int i=0,j=0;
          set<int> Set;
          for(int i=0;i<n1;i++){
              while (j < n1 && Set.find(arr[j])==Set.end())
              {
                  Set.insert(arr[j]);
                  j++;
              }
              ans+=(((j-i)%MOD*(j-i+1)%MOD)%MOD)/2;
              Set.erase(arr[i]);
          }
          cout << ans%MOD<<endl;
    }
    return 0;
}