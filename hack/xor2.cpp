#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      int n;
      //cin >> n;
      int n1;
      cin >>n1;

      
      vector<int> arr(n1,0);
      cin >> arr[0];
        int a=arr[0];
      for(int q=0;q<n1;q++){
        cin >> arr[q];
        a=a^arr[q];
      }
      cout << a<<endl;
      int c=1;
      while(a){
          if(1&&a){
              c*=10;
              break;
          }
          c=c>>1;
      }
       int b;
      for(int q=0;q<n1;q++){

      }
      cout << b<<endl;
      
    //   for(int q=0;q<n1;q++){
    //     cout << q << ":" <<arr[q]<<"\n";
    //   }
      cout << endl;
    }
    return 0;
}