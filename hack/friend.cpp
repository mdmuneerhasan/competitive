#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
int pairup(int n){
    if(v[n])return v[n];
    if(n<3){
        return v[n]=n;
    }
    return v[n]=(n-1)*pairup(n-2)+pairup(n-1);


}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
      int n;
      cin >> n;
      v.resize(n+1,0);
      cout << pairup(n)<<endl;
    }
    return 0;
}