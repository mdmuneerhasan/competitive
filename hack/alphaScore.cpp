#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> vec;
int n1;
int m= 1000000007;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      
      cin >>n1;
      vec.resize(n1,0);
      priority_queue<int> dec;
      priority_queue<int,vector<int> , greater<int>> inc;
      for(int q=0;q<n1;q++){
        cin >> vec[q];
      }
    //   while(!dec.empty()){
    //       cout << dec.top()<<endl;dec.pop();
    //   }
    //   cout << "inc"<<endl;
    //   while(!inc.empty()){
    //       cout << inc.top()<<endl;inc.pop();
    //   }
    int sum=0;int ans=0;
      for(int i=0;i<n1;i++){
          int n=vec[i];
          inc.push(n);
          while(!dec.empty() && n<=dec.top()){
              sum-=dec.top();
              inc.push(dec.top());
              dec.pop();
          };
          while(!inc.empty() && n>inc.top()){
              sum+=inc.top();
              dec.push(inc.top());
              inc.pop();
          };
          ans+=sum;
          ans%=m;
        //   cout << sum<<endl;
      }
      cout << ans%m<<endl;




    }
    return 0;
}