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
int n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
string n;
int solve(string processing){
    if(processing.size()==0){
        return 1;
    }  
    if(processing.size()==1){
        if(processing[0]=='*')return 9;
        else return 1;
    }
    char c1=processing[0];
    char c2=processing[1];
    int a=0,b=0;
    if(c1=='*'){
        return solve(processing.substr(1))*9;
    }else if(c1=='1'){
        if(c2=='*'){
            return solve(processing.substr(2))*18;
        }else{
            return solve(processing.substr(2))*2;     
        }
    }else if(c1=='2'){
        if(c2=='*'){
            return solve(processing.substr(2))*12;
        }else{
            return solve(processing.substr(2))*2;     
        }
    }
        return solve(processing.substr(1));
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      cin >> n;
      cout << solve(n)<<endl;
      
    }
    return 0;
}