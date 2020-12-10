#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
const int MOD =1000000009;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<bool> vec;
vector<int> pre;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
int solve(){
    

    for(int j=2;j<n1;j++){
    ans=0;
    for(int i=1;i<=k;i++){
        if(j-i>=0){
            ans+=pre[j-i]%MOD;
            ans%=MOD;
        }else break;
    }
    if(vec[j]==0)
        pre[j]=ans;
        else pre[j]=0;
    }

    return pre[n1-1];

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >>n1>>k;
        vec.clear();
        vec.resize(n1,0);
        pre.clear();
        pre.resize(n1,0);
        pre[0]=1;pre[1]=1;
        for(int q=0;q<n1;q++){
          cin >> startPoint;
          vec[q]=startPoint;
        }
        cout << solve()<<endl;
      
    }
    return 0;
}