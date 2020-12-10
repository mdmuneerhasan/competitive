#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
      int n;
      cin >> n;
      if(n==1){
          cout << "Second"<<endl;
          continue;
      }
      if(n==0){
          cout << "Second"<<endl;
          continue;
      }
      while (n%2==0)
      {
          n/=2;
      }
      
      while (n%3==0)
      {
          n/=3;
      }
      
      while (n%5==0)
      {
          n/=5;
      }
      if(n==1){
          cout << "First"<<endl;
      }else{
          cout << "Second"<<endl;
      }
      
    }
    return 0;
}