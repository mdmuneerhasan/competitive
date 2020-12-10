
#include<bits/stdc++.h>
using namespace std;
#define int long long int
stringstream vin,vout;
vector<int> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;
string solve(string s,bool start){
    if(s.empty())return s;
    if(start){
        if(s[0]==')')return "";
        return s[0]+solve(s.substr(1),start);
    }else{
        if(s[0]=='(')return solve(s.substr(1),1);
        return solve(s.substr(1),start);
    }

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //signature(true);
    //cin >>t;    while (t--)
    {   
          
          string s;
          cin >> s;
          cout << solve(s,0)<<endl;
          
    }
    return 0;
}