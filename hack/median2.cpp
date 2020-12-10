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
      vector<int> arr2(n1,0);
      for(int q=0;q<n1;q++){
        cin >> arr2[q];
      }
      int i=0; int j=0,l=0,l1=0,k=0;
      while(k<n1){
                l1=l;
          if(arr[i]<arr2[j]){
              
              l=arr[i];
              i++;
          }else {
              l=arr2[j];
              j++;
            
      }
      k++;
    }
    cout << l<<endl;
    // cout << l1<<endl;
    }
    return 0;
}