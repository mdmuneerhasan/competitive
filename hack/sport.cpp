#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
unordered_map<int,unordered_map<int,unordered_map<int,int>>>dp;
int n;
ll f(ll i,char prev2,char prev1)
{
    if(i==(n)) 
    {
        if(prev2=='C' && prev1=='C') return 3;  // all C ,F and H can be played on last day
        if(prev2=='C' && prev1=='H') return 2;  // all C ,F and H can be played on last day
        if(prev2=='C' && prev1=='F') return 2;  // all C ,F and H can be played on last day
        if(prev2=='H' && prev1=='F') return 1;  // only cricket can be played on last day
        if(prev2=='H' && prev1=='C') return 2;  // only cricket can be played on last day
        if(prev2=='F' && prev1=='C') return 3;  // all C ,F and H can be played on last day
        if(prev2=='F' && prev1=='H') return 2;  // all C ,F and H can be played on last day
        
    } 
    if(dp[i][prev2][prev1]) return dp[i][prev2][prev1];
    ll ans=0; 
    // if cricket is played on first day 
    if(prev1=='C'){
        if(prev2=='C')
        ans = (f(i+1,'C','C') + f(i+1,'C','F') + f(i+1,'C','H'))%mod;
        if(prev2=='F')
        ans = (f(i+1,'C','C') + f(i+1,'C','F') + f(i+1,'C','H'))%mod;
        if(prev2=='H')
        ans = (f(i+1,'C','C') + f(i+1,'C','F'))%mod;
    }
    else if(prev1=='F'){
        if(prev2=='C')
        ans = (f(i+1,'F','C') + f(i+1,'F','H'))%mod;
        if(prev2=='H')
        ans = (f(i+1,'F','C') )%mod;
    }
    else if(prev1=='H'){
        if(prev2=='C')
        ans = (f(i+1,'H','F') + f(i+1,'H','C'))%mod;
        if(prev2=='F')
        ans = (f(i+1,'H','F') + f(i+1,'H','C'))%mod;
    }

    return dp[i][prev2][prev1]= ans;
}
#define MOD 1000000007
int power(int a,int p){
    if(p==1){
        return a%MOD;
    }
    int ans=power(a,p/2)%MOD;
    ans=ans*ans;
    ans%=MOD;
    if(p&1){
        ans=ans*a;
        ans%=MOD;
    }
    return ans;
}

int main() {
    cin>>n;
    char anychar='X';
    
    if(n<3){
        if(n==1)cout << 3<<endl;
        if(n==2)cout << 7<<endl;
    return 0;
    }
    n--;
    cout<<(f(2,'F','C') +f(2,'H','C') +f(2,'C','C') +
     f(2,'H','F')+f(2,'C','F')+
      f(2,'F','H')+f(2,'C','H'))%mod;  // try every sport on first day
}
