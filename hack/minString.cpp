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
char get(char a,char b){
    if(a=='a'&&b=='b')return 'c';
    if(a=='b'&&b=='c')return 'a';
    if(a=='c'&&b=='a')return 'b';
    if(a=='b'&&b=='a')return 'c';
    if(a=='c'&&b=='b')return 'a';
    if(a=='a'&&b=='c')return 'b';
    return 'z';
}
unordered_map<string,unordered_map<int,int>>dp;
int solve(int index,string s){
    if(index==s.size()){
        return index;
    }
    if(dp[s][index])return dp[s][index];
    int a=INT_MAX,b=INT_MAX;
    a=solve(index+1,s);
    if(index>0 && s[index]!=s[index-1]){
        b=solve(index-1,s.substr(0,index-1)+get(s[index-1],s[index])+s.substr(index+1));
    }
    return dp[s][index]=min(a,b);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        dp.clear();
        string s;
        cin >> s;
        n=s.size();
        for(int i=0;i<s.size()-1;){
            if(s[i]!=s[i+1]){
                s=get(s[i],s[i+1])+s.substr(i+2);
                i=0;
            }else{
                i++;
            }
            

        }
        // cout << s<<endl;
        cout << s.size()<<endl;
      
    }
    return 0;
}