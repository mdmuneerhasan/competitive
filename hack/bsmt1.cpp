#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
int n1;
int go(int k){
    if(v[k])return v[k];
    if(k==1){
        return 0;
    }
    int a=INT_MAX,b=INT_MAX,c=INT_MAX;
    if(k>1){
       a= 1+go(k-1);
        
    }
    if(k%2==0){
       b= 1+go(k/2);
        
    }
    if(k%3==0){
       c=1+ go(k/3);
        
    }


    return v[k]=min(a,min(b,c));
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    
    for(int i=0;i<t;i++)
    {
      int n;
      cin >> n;
      v.resize(n,0);
      cout << "Case "<<i+1<<": "<<go(n)<<endl;
      
    }
    return 0;
}