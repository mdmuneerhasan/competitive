#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define MOD 1000000007
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<int> vec;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
int dp[1000][1000];
int solve(int index,int k){
    if(k==0 && index==n1)return 1;
    if(k<0 || index==n1)return 0;    
    // if(dp[k][index]) return dp[k][index]%MOD;
    dp[k][index]=solve(index,k-vec[index])%MOD+solve(index+1,k)%MOD;
    return dp[k][index];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        for(int i=0;i<1000;i++){
            for(int j=0;j<1000;j++){
                dp[i][j]=0;
            }
        }
        cin>>n1;
		int x;
        vec.clear();
        for(int q=0;q<n1;q++){
			cin >>x;
			vec.push_back(x);
        }
        cin >> k;
        
        cout << solve(0,k)<<endl;

      
    }
    return 0;
}