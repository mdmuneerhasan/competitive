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
int dp[100]={0};
int fun(int len){
    if(len<3){
        return 0;
    }
    if(len==3){
        return 3;
    }
    if(len%3==1){
        return 2*7*fun(len-1)%MOD;
    }
    if(len%3==2){
        return 3*7*7*fun(len-2)%MOD;
    }

    int ans=fun(len-3)%MOD;
    return ((4*7*7*7+ans)%MOD*ans)%MOD;
    
}
int solve(string num){
    int x=num[0]-'0';
    if(x<3){
        return (x+1)*fun(num.length()-1);
    }else if(x<6){

    }else if(x<9){

    }else{

    } 

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        string startPoint ,endPoint;
      cin >> startPoint>>endPoint;
      cout <<solve(endPoint)-solve(startPoint)<<endl;
      
    }
    return 0;
}