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
    //   cin >> n;
      int n1;
      cin >>n1;
      vector<pair<int,int>> arr(n1);
      for(int q=0;q<n1;q++){
        cin >> arr[q].first;
        arr[q].second=q;
      }    
      sort(arr.begin(),arr.end());


    //   for(int q=0;q<n1;q++){
    //     cout  <<arr[q].first<<" "<<arr[q].second<<" "<<"\n";
    //   }
    //   cout << endl;


    int ans=0,c=0;
    for(int i=0;i<n1;i++){
        if(arr[i].second>=ans){
            ans=arr[i].second;
            c++;
        }
    }
    
    cout << c<<endl;
    
    
    }
    return 0;
}