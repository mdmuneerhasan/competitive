#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
const int MOD = 1000000007;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<int> vec;
int n,n1,n2,startPoint,k,endPoint,r,ans=1,cnt=0,q=0,qry=0;
int power(int a,int b){
    int res=1;
    while (b)
    {
        if(b&1)res=(res%MOD*a%MOD)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >> n >> r;
        int fact[n+1];
        fact[0]=1;
        for(int i=1;i<=n;i++){
            fact[i]=(fact[i-1]%MOD*i%MOD)%MOD;
        }

        cout << (fact[n]%MOD*power(fact[n-r],MOD-2)%MOD
        *power(fact[r],MOD-2)%MOD)%MOD;

    }
    return 0;
}