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
      cin >> n;
      vector<pair<int,int>> arr(n);
      for(int q=0;q<n;q++){
        cin >> arr[q].first >> arr[q].second;
      }
      sort(arr.begin(),arr.end());
      int count=0;
      for(int i=0;i<n-1;i++){
          int diffC=arr[i+1].first-arr[i].first,
          sumR=arr[i].second+arr[i].second;
          if(diffC>=sumR){
          }else{
              // remove bigger
              if(arr[i].second>arr[i+1].second){
                  arr.erase(arr.begin()+i);
              }else{
                  arr.erase(arr.begin()+i+1);
              }
              count++;
            //   i--;
          }
      }
      for(int q=0;q<n;q++){
        cout << q << ":" <<arr[q].first<<"\n";
      }
      cout << endl;
      cout << count<<endl;


    }
    return 0;
}