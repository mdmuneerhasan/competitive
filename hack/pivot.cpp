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
      int ans=0;
      vector<int> arr(n1,0);
      for(int q=0;q<n1;q++){
        cin >> arr[q];
        if(arr[ans]<arr[q]){
            ans=q;
        }
      }
      cout << ans<<endl;


    }
    return 0;
}