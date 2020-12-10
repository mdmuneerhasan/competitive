#include<bits/stdc++.h>
using namespace std;
#define int long long int
stringstream vin,vout;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<int> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    unordered_map<int,vector<int>> divisor;
    for(int i=2;i*i<1000000;i++){
        if(divisor[i].size()==0){
            for(int j=2*i;j<1000000;j+=i){
                divisor[j].push_back(i);
            }
            divisor[i].push_back(i);
        }
    }

    // for(int i=0;i<100;i++){
    //     cout << i <<": ";
    //     for(auto x:divisor[i]){
    //         cout << x<<" ";
    //     }
    //     cout <<endl;
    // }


    cin >>t;    while (t--)
    {
        int mod=1000000007;
        cin >>n1;
        unordered_map<int,int> cnt;
        for(int q=0;q<n1;q++){
          cin >> k;
          for(auto x:divisor[k]){
              while(k%x==0&&k>1){
              k/=x;
              cnt[x]++;
              }
          }
        }
        ans=1;
        for(auto x:cnt){
            ans=(ans%mod*(x.second+1)%mod)%mod;
            
        }
        cout << ans<<endl;
    }
    return 0;
}