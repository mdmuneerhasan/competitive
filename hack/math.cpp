#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
int a,n,p,ans=1,k=1;
int power(int a,int n,int p){
  if(v[n])return v[n];
  if(n==1){
    return a%p;
  }
  int pow=power(a,n/2,p);
  int r=(pow%p*pow%p)%p;
  if(n&1){
    r*=a%p;
  }
  return v[n]=r%p;
}
void go(int n){
  if(n==0){
    return ;
  }
  a=power(a,n,p);
  go(n-1);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
      cin >> a>> n >>p;
      v.resize(n+1,0);
      go(n);
      cout << a<<endl;
    }
    return 0;
}