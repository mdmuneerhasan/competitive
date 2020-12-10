#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
void go(string pro,string un,string safe){
  if(!un[0]){
    if(pro>safe){
      cout << pro<<endl;
    }
    return ;
  }
    for(int i=0;i<un.size();i++){
      go(pro+un[i],un.substr(0,i)+un.substr(i+1),safe);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      string n;
      cin >> n;
      go("",n,n);
    }
    return 0;
}