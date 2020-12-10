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
      for(int q=0;q<n1;q++){
        cin >> arr[q];
      }
      int i,c=0;
      for( i=0;i<n1;){
          c++;
          if(arr[i]==0){
              break;
          }else{
              i+=arr[i];
          }
      }
      if(i>=n1)
      cout << c<<endl;



    }
    return 0;
}   