#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
int find(int k){
    if(k==1){
        return 1;
    }if(k==2){
        return 3;
    }
    if(k==3){
        return 5;
    }    
    if(v[k]){
        return v[k];
    }
    return v[k]=find(k-1)+find(k-2);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
      int n;
      cin >> n;
      int ans=0;
      v.resize(n+1,0);
      
      cout << find(n)<<endl; 




    }
    return 0;
}