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
      int a=0;
      for(int q=0;q<n1;q++){
        cin >> arr[q];
        a^=arr[q];
      }
    //   cout <<a<< endl;
      int cnt=0,cnt2=0;
      int s=a;
      while(a){
          if(a&1)break;
          a=a>>1;
          cnt ++; 
      }
    //   cout << a<<endl;
      int b=0;
      
      for(int q=0;q<n1;q++){
        cnt2=0;
        int k=arr[q];
        while(cnt2<cnt){
            k=k>>1;
            cnt2++;
        }
        if(k&1){
            b=b^arr[q];
        }
      }
      int k= s^b;
      cout <<k<<endl;
      cout << b<<endl;


    }
    return 0;
}