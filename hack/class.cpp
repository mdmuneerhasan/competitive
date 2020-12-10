#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
int find(int n){
    // cout << n<<endl;
    if(v[n]){
        return v[n];
    }
    if(n==0){
        return 0;
    }
    int sum=1;
    for(int i=0;i<n;i++){
        if(i==1)continue;
        if(i>=4){
            sum+=(n-i)*find(i-3);
        }else{
            sum+=n-i;
        }
    }
    return v[n]=sum;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
      int n;
      cin >> n;
      v.resize(n+4);
      v[1]=2;
      v[2]=3;
      v[3]=5;      
      cout <<"#"<<n<<" : " <<find(n)<<endl;
    }
    return 0;
}