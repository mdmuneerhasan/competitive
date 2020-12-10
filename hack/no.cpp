#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
int n1;
map<string ,int> ma;
void go(string pro,string un,string safe){
  if(!un[0]){
    if(!ma[pro]){
      int i=0;
      ma[pro]=1;
    
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
      cin >>n1;
      v.resize(n1,0);
      for(int q=0;q<n1;q++){
        cin >> v[q];
      }
      sort(v.begin(),v.end());
       for(int q=0;q<n1;q++){
        n+=v[q]+'0';
      }

      go("",n,n);
      string pro;
      vector<string>temp;
      for(auto x:ma){
              int i=0;
              pro=x.first;
              temp.push_back(pro);
      }
     
      for(auto x:temp){
              int i=0;
              pro=x;
      while(pro[i]){
        cout <<pro[i++] <<" ";
      }
    cout <<endl;
    
      }
    
    
    
    }
    return 0;
}