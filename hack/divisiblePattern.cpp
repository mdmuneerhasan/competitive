/*
* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 00:01:16 Sunday 05-April:2020
*/
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
void signature(bool enable){
    if(!enable)return;
    cout << "Sunday 05-April:2020"<<endl;
    cout << "Name : Muneer Hasan"<<endl;
    cout << "Roll No.: 17BCS054"<<endl;
}
vector<int> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,q=0,qry=0;
string x;
string s;
int mod=1000000007;
int dp[10007][5][5][5][5];
int solve(int index,int two,int three,int five,int seven){

    if(index==vec.size()){
        if(two>=3 && three>=2 && five>=1 && seven>=1){
            return 1;
        }
        return 0;
    }
    if( dp[index][two][three][five][seven]!=-1)return  dp[index][two][three][five][seven];
    int indexOfStart=vec[index];
    int a=0,b=0,c=0,d=0;
    while (indexOfStart%2==0 &&indexOfStart && a<=3){
        indexOfStart/=2;
        a++;
    }
    while (indexOfStart%3==0 &&indexOfStart&& b<=2){
        indexOfStart/=3;
        b++;
    }
    while (indexOfStart%5==0 &&indexOfStart&& c<=1){
        indexOfStart/=5;
        c++;
    }
    while (indexOfStart%7==0 &&indexOfStart&& d<1){
        indexOfStart/=7;
        d++;
    }
    int k=3;
    int a1=solve(index+1,two,three,five,seven);
    int b1=solve(index+1,min(two+a,k),min(three+b,k),min(five+c,k),min(seven+d,k));
    return dp[index][two][three][five][seven]=(a1%mod+b1%mod)%mod;
}        
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //signature(true);
    //cin >>t;    while (t--)
    {   cin >> x >>s;
        int l=0,k=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<s.size();i++){
            if(x[0]==s[i]){
                k=0;
                while(x[k]==s[i+k]&&i+k<s.size())k++;
                if(k==x.size())
                vec.push_back(i+1);
            }
        }
        cout << solve(0,0,0,0,0)<<endl;
        


          
          
          
    }
    return 0;
}